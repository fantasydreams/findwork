#pragma once
#include <chrono>
#include <cstdint>
#include <cstring>
#include <mutex>
#include <sys/poll.h>
#include <type_traits>
#include <sys/event.h>
#include <unistd.h>
#include <poll.h>
#include <memory>
#include <vector>
#include <thread>
#include <sys/eventfd.h>
#include <iostream>

enum ErrRet {
    ErrReciveTimeOut = 1,
};

uint32_t IntHash(uint64_t keytype) {
	keytype += ~(keytype << 15);
	keytype ^=  (keytype >> 10);
	keytype +=  (keytype << 3);
	keytype ^=  (keytype >> 6);
	keytype += ~(keytype << 11);
	keytype ^=  (keytype >> 16);
	return keytype;
}

uint32_t MurmurHash32 ( const void * keytype, int len, uint32_t seed ) {
    // 'm' and 'r' are mixing constants generated offline.
    // They're not really 'magic', they just happen to work well.

    const uint32_t m = 0x5bd1e995;
    const int r = 24;

    // Initialize the hash to a 'random' value

    uint32_t h = seed ^ len;

    // Mix 4 bytes at a time into the hash

    const unsigned char * data = (const unsigned char *)keytype;

    while(len >= 4) {
        uint32_t k = *(uint32_t*)data;

        k *= m;
        k ^= k >> r;
        k *= m;

        h *= m;
        h ^= k;

        data += 4;
        len -= 4;
    }

    // Handle the last few bytes of the input array

    switch(len) {
        case 3: h ^= data[2] << 16;
        case 2: h ^= data[1] << 8;
        case 1: h ^= data[0];
        h *= m;
    };

    // Do a few final mixes of the hash to ensure the last few
    // bytes are well-incorporated.

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    return h;
} 

template <typename KeyType, typename Any = KeyType>
struct __DefaultHash {
    template<typename AnyType> 
    struct False {
        static constexpr bool bValue = false;
    };

    static uint32_t Hash(const KeyType& keytype) {
        static_assert(False<KeyType>::bValue, "provider Hash Function for this type");
    };
};

template <typename KeyType>
struct __DefaultHash<KeyType, std::enable_if<std::is_integral<KeyType>::value, KeyType> > {
    static uint32_t Hash(const KeyType& keytype) {
        return IntHash(keytype);
    }
};

template <typename KeyType, typename Any = KeyType>
struct __DefaultCompare {
    static bool IsEqual(const KeyType& keytypea, const KeyType& keytypeb) {
        return keytypea == keytypeb;
    }
};


enum SingleCsStrategyType {
    TYPE_STRICT_AS_CONSISTENCY = 1,
    TYPE_RETUTRN_AS_CONSISTENCY = 2,
    TYPE_KEYTYPE_AS_CONSISTENCY = 3,
};

template <class KeyType>
struct SingleDefaultConfig {
    static const int m_iBucketCnt = 1 << 15;
    static const int m_iTimeOut = 1500;
    static const int m_iWaitTimeInterval = 10;
    static const int m_iCsStrategy = SingleCsStrategyType::TYPE_STRICT_AS_CONSISTENCY;

    static uint32_t Hash(const KeyType& keytype) {
        return __DefaultHash<KeyType>::Hash(keytype);
    }

    static bool IsEqual(const KeyType& keytypea, const KeyType& keytypeb) {
        return __DefaultCompare<KeyType>::IsEqual(keytypea, keytypeb);
    }
};


class Event {
public:
    Event() {
        m_iFd = eventfd(0, EFD_CLOEXEC);
        if(m_iFd < 0) {
            std::cerr << "create fd err" << std::endl;
            abort();
        }
    }
    ~Event() {
        close(m_iFd);
    }

    void Notify() {
        uint64_t iVal = 1;
        while(true) {
            int iRet = write(m_iFd, &iVal, sizeof(iVal));
            if(iRet == -1 && errno == EINTER) {
                continue;
            }

            if(iRet != sizeof(iVal)) {
                std::cerr << "write fd fail " << __FILE__ << " " << __LINE__ << " " << iRet << std::endl;
                abort();
            }else {
                break;
            }
        }
    }

    bool Wait(int iMs) {
        struct pollfd fd = {0};
        fd.fd = m_iFd;
        fd.events = POLLIN;
        int iRet = poll(&fd, 1, iMs);
        if(iRet > 0) {
            uint64_t iVal = 0;
            iRet = read(m_iFd, &iVal, sizeof(iVal));
            if(iRet != sizeof(iRet)) {
                std::cerr << "read fd faile ret" << iRet << " fd " << m_iFd << std::endl;
                abort();
            }
            
            return true;
        }else {
            if(iRet == 0 || iRet == -1 && errno == EINTER) {
                return false;
            } else {
                std::cerr << "poll fd faile ret" << iRet << " fd " << m_iFd << " " << strerror(errno) << std::endl;
                abort();
            }
        }
    }
private:
    int m_iFd;
};


class LocalSeqAlloctor {
public:
    inline uint64_t GetNext() {
        return __sync_fetch_and_add(&m_iSeq, 1);
    }

    LocalSeqAlloctor(int iBegin = 0) : m_iSeq(iBegin) {}
private:
    uint64_t m_iSeq;
};

class TimeMeature {
public:
    TimeMeature() {
        m_RecordPoint = std::chrono::steady_clock::now();
    }

    int Elapse() {
        return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - m_RecordPoint).count();
    }
private:
    std::chrono::time_point<std::chrono::steady_clock> m_RecordPoint;
};


template <typename KeyType, typename ValueType, typename Config = SingleDefaultConfig<KeyType> >
class SingleCaller {
public:
    template<typename Caller>
    SingleCaller(const Caller& poFunc) : m_poFunc(poFunc){
        std::cout << "caller init " << __PRETTY_FUNCTION__ << std::endl;
    }

    int Call(const KeyType& oKey, ValueType* poValue) {
        KeyWrap oKeyWrap(oKey);
        return CallFunc(oKeyWrap, poValue);
    }


private:
    struct KeyWrap {
        const KeyType & m_oKey;
        int  m_iIdx;
        KeyWrap(const KeyType& oKey) : m_oKey(oKey), m_iIdx(Config::Hash(oKey) % Config::iBucketCnt) {}
    };

    struct Task {
        enum TaskStatus {
            S_ENABLED,
            S_WRITTEN, 
            S_DONE,
            S_DISABLED, 
        };
        //等待线程S_ENABLED<-->S_DISABLED
        //工作线程S_ENABLED->S_WRITINE->(S_ENABLED|S_DONE)

        Event m_oEvent;
        const KeyWrap & m_oKeyWrap;
        int m_iRet;
        ValueType * m_poValue;
        uint64_t m_iExpectSeq;
        int m_iStatus; // @TaskStatus

        Task(const KeyWrap& oKeyWrap, uint64_t iExpectSeq, ValueType* poValue) : m_oKeyWrap(oKeyWrap), m_iExpectSeq(iExpectSeq), m_poValue(poValue), m_iRet(-1), m_iStatus(Task::TaskStatus::S_DISABLED) {}
    };

    struct LinkNode {
        LinkNode(const std::shared_ptr<Task> & poTask) : m_poTask(poTask), m_pNext(nullptr), m_pPrev(nullptr), m_bInLink(false) {}
        std::shared_ptr<Task> m_poTask;
        LinkNode * m_pNext;
        LinkNode * m_pPrev;
        bool m_bInLink;
    };
    
    class SingleCallManager {
    public:
        SingleCallManager() {
            memset_s(m_ArrayCallLock, sizeof(m_ArrayCallLock), 0, sizeof(m_ArrayCallLock));
            memset_s(m_ArrayHead, sizeof(m_ArrayHead), 0, sizeof(m_ArrayHead));
            memset_s(m_ArrAyTail, sizeof(m_ArrAyTail), 0, sizeof(m_ArrAyTail));
        }

        bool TryCall(const KeyWrap& oKeyWrap, ValueType) {
            return __sync_bool_compare_and_swap(&m_ArrayCallLock[oKeyWrap.m_iIdx], false, true); 
        }

        bool CallDone(const KeyType& oKeyWrap) {
            return __sync_bool_compare_and_swap(&m_ArrayCallLock[oKeyWrap.m_iIdx], true, false);
        }

        void Notify(const KeyWrap& oKeyWrap, uint64_t iSeq, int iRet, ValueType* poValue) {
            TimeMeature oTimeMeature;
            int iNotifyCnt = 0;
            while( true ) {
                std::shared_ptr<Task> poTask = GetOneTaskToNotify(oKeyWrap.m_iIdx, oKeyWrap.m_oKey, iSeq);
                if( poTask ) {
                    if(poTask->m_iStatus == Task::S_WRITING) {
                        *poTask->poValue = *poValue;
                        poTask->m_iRet = iRet;
                        poTask->m_iStatus = Task::S_DONE;
                        poTask->m_oEvent.Notify();
                        ++iNotifyCnt;
                    } else {
                        std::cerr << "idx " << oKeyWrap.m_iIdx << " conflict" << std::endl;
                        poTask->m_oEvent.Notify();
                        break;
                    }
                }else {
                    break;
                }
            }

            if(iNotifyCnt) {
                std::cout << "idx " << oKeyWrap.m_iIdx << " notify cnt " << iNotifyCnt << " cost " << oTimeMeature.Elapse() << std::endl;
            }
        }

        bool Wait(const KeyWrap& oKeyWrap, const std::shared_ptr<Task>* poTask) {
            LinkNode * poNode = new LinkNode(poTask);
            poTask->status = Task::S_ENABLED;
            AddToLink(oKeyWrap.m_iIdx, poNode);
            while( true ) {
                poTask->m_oEvent.Wait(Config::m_iWaitTimeInterval);
                if(poTask->m_iStatus == Task::S_DONE) {
                    break;
                }else if(poTask->m_iStatus == Task::S_ENABLED) { 
                    if(__sync_bool_compare_and_swap(&poTask->m_iStatus, Task::S_ENABLED, Task::S_DISABLED)) {
                        std::cerr << "timeout" << oKeyWrap.m_iIdx << std::endl;
                        break;
                    }else {
                        if(poTask->m_iStatus == Task::S_DONE) {
                            break;
                        }else {
                            continue;
                        }
                    }

                }else {
                    continue;
                }
            }

            RemoveFromLink(oKeyWrap.m_iIdx, poNode);
            delete poNode;
            return poTask->m_iStatus == Task::S_DONE;
        }



    private:

        LinkNode * AddToLink(int iIdx, LinkNode * poNode) {
            std::lock_guard<std::mutex> oLock(m_ArrayMutex[iIdx]);
            poNode->m_pPrev = m_ArrAyTail[iIdx];
            poNode->m_bInLink = true;

            if (m_ArrayHead[iIdx] == nullptr) {
                m_ArrayHead[iIdx] = m_ArrAyTail[iIdx] = poNode;
            } else {
                m_ArrAyTail[iIdx]->next = poNode;
                m_ArrAyTail[iIdx] = poNode;
            }
            return poNode;
        }

        void RemoveFromLinkWithNoLock(int iIdx, LinkNode * poNode) {
            if (poNode == nullptr || !poNode->m_bInLink) {
                return;
            }

            if (poNode == m_ArrayHead[iIdx]) {
                m_ArrayHead[iIdx] = poNode->m_pNext;
                if (m_ArrayHead[iIdx]) {
                    m_ArrayHead[iIdx]->m_pPrev = nullptr;
                }
            } else {
                poNode->m_pPrev->m_pNext = poNode->m_pNext;
            }

            if (poNode == m_ArrAyTail[iIdx]) {
                m_ArrAyTail[iIdx] = poNode->m_pPrev;
                if (m_ArrAyTail[iIdx]) {
                    m_ArrAyTail[iIdx]->m_pNext = NULL;
                }
            } else {
                poNode->m_pNext->m_pPrev = poNode->m_pPrev;
            }
            poNode->m_bInLink = false;
        }

        void RemoveFromLink(int iIdx, LinkNode* poNode) {
            std::lock_guard<std::mutex> oLock(m_ArrayMutex[iIdx]);
            return RemoveFromLinkWithNoLock(iIdx, poNode);
        }


        std::shared_ptr<Task> GetOneTaskToNotify(int iIdx, const KeyType& oKey, uint64_t iSeq) {
            std::lock_guard<std::mutex> oLock(m_ArrayMutex[iIdx]);
            LinkNode * poNode = m_ArrayHead[iIdx];
            while(poNode != nullptr) {
                if(__sync_bool_compare_and_swap(&poNode->m_poTask->m_iStatus, Task::S_ENABLED, Task::S_WRITTEN)) {
                    if(poNode->Task->iExpectSeq < iSeq && Config::IsEqual(oKey, poNode->m_poTask->m_oKeyWrap.m_oKey)) {
                        RemoveFromLinkWithNoLock(iIdx, poNode);
                        return poNode->m_poTask;
                    }else {
                        poNode->m_poTask->m_iStatus = Task::S_ENABLED;
                    }
                }else {
                    std::cerr << "task status changed, skip idx " <<iIdx << "status " << poNode->m_poTask->m_iStatus << std::endl;
                    LinkNode * poNext = poNode->m_pNext;
                    RemoveFromLinkWithNoLock(iIdx, poNode);
                    poNode = poNext;
                    continue;
                }

                poNode = poNode->m_pNext;
            }

            if(m_ArrayHead[iIdx] != nullptr) { // HASH冲突且seq不满足要求，唤醒其他线程去执行
                poNode = m_ArrayHead[iIdx];
                RemoveFromLinkWithNoLock(iIdx, poNode);
                return poNode->m_poTask;
            }

            return nullptr;
        }

    private:
        bool m_ArrayCallLock[Config::m_iBucketCnt];
        std::mutex m_ArrayMutex[Config::m_iBucketCnt];
        LinkNode* m_ArrayHead[Config::m_iBucketCnt];
        LinkNode* m_ArrAyTail[Config::m_iBucketCnt];
    };


    int CallFunc(const KeyWrap& oKeyWrap, ValueType* poValue) {
        TimeMeature oT;
        uint64_t iSeq = m_oSeqAllocator.GetNext();
        int iRet = -1;
        std::shared_ptr<Task> poTask = nullptr;
        while(true) {
            if(m_oMgr.TryCall(oKeyWrap, poValue)) {
                uint64_t iBeginSeq = m_oSeqAllocator.GetNext();
                iRet = m_poFunc(oKeyWrap, poValue);
                uint64_t iEndSeq = m_oSeqAllocator.GetNext();
                m_oMgr.CallDone(oKeyWrap);

                uint64_t iGetSeq;
                if(Config::m_iCsStrategy == SingleCsStrategyType::TYPE_STRICT_AS_CONSISTENCY) {
                    iGetSeq = iBeginSeq;
                }else if(Config::m_iCsStrategy == SingleCsStrategyType::TYPE_RETUTRN_AS_CONSISTENCY) {
                    iGetSeq = iEndSeq;
                }else {
                    iGetSeq = UINT64_MAX;
                }

                m_oMgr.Notify(oKeyWrap, iGetSeq, iRet, poValue);
                return iRet;
            }else {
                if(poTask == nullptr) {
                    poTask.reset(new Task(oKeyWrap, iSeq, poValue));
                }

                if(m_oMgr.Wait(oKeyWrap, poTask)) {
                    std::cout << "other refresh seq idx " << oKeyWrap.m_iIdx << " ret " << poTask->m_iRet << " cost " << oT.Elapse() << std::endl; 
                    return poTask->m_iRet;
                }else {
                    int iTimePast = oT.Elapse();
                    if(iTimePast > Config::m_iTimeOut) {
                        std::cerr<< "all time out, break idx " << oKeyWrap.m_iIdx << " cost " << oT.Elapse() << std::endl;
                        break;
                    }

                    std::cout << "wait timeout retry idx " << oKeyWrap.m_iIdx << " cost " << oT.Elapse() << std::endl; 
                }
            }
        }

        return ErrRet::ErrReciveTimeOut;
    }

private:
    std::function<int (const KeyType&, ValueType *)> m_poFunc;
    LocalSeqAlloctor m_oSeqAllocator;
    SingleCallManager m_oMgr;
};


template <typename KeyType, typename ValueType, typename Caller, typename Config = SingleDefaultConfig<KeyType> >
class SingleCall {
public:
    static int Call(const KeyType& oKey, ValueType* poValue) {
        return GetCallerInstance()->Call(oKey, poValue);
    }
private:
    static SingleCall<KeyType, ValueType, Config> * GetCallerInstance() {
        static SingleCaller<KeyType, ValueType, Config> oIns(&Caller::Call);
        return &oIns;
    }
}