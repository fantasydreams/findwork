#include <mutex>
#include <atomic>
#include <utility>
#include <mutex>
#include <pthread.h>
#include "lib/comm/class/no_copyable.h"

namespace comm {
// std::atomic_flag m_flag.test_and_set(std::memory_order_acquire) 和 m_flag.clear(std::memory_order_release)结合可以当做一个简单的自旋锁
// 在上锁的时候，如果 m_flag.test_and_set 返回 false，则表示上锁成功（此时 while 不会进入自旋状态），因为此前 m_flag 的标志位为 false(即没有线程对 lock 进行上锁操作)，但调用 test_and_set 后 lock 的标志位为 true，说明某一线程已经成功获得了 lock 锁。
// 原子变量
template <class Type, typename... Args>
class Singleton : public NonCopyable {
    public:
        static Type* GetInstance(Args&&... args) {
            if(m_pInstace == nullptr) {
                while(m_flag.test_and_set(std::memory_order_acquire)) {} // spin
                if(m_pInstace == nullptr) {
                    m_pInstace = new Type(std::forward<Args>(args)...);
                    m_flag.clear(std::memory_order_release);
                }
            }
            return m_pInstace;
        };

        static void Destory() {
            delete m_pInstace;
            m_pInstace = nullptr;
        }
    private:
        static Type* m_pInstace;
        static std::atomic_flag m_flag;
};

template <class Type, typename... Args> Type* Singleton<Type, Args...>::m_pInstace = nullptr;
template <class Type, typename... Args> std::atomic_flag Singleton<Type, Args...>::m_flag = ATOMIC_FLAG_INIT;


template <class Type, typename... Args>
class SingletonMutex :public NonCopyable {
    public:
        static Type* GetInstance(Args&&... args) {
            Type* pInstace = m_pInstace.load(std::memory_order_acquire);
            if(pInstace == nullptr) {
                std::lock_guard<std::mutex> oLock(m_oMutex);
                pInstace = m_pInstace.load(std::memory_order_relaxed);
                if(pInstace == nullptr) {
                    pInstace = new Type(std::forward<Args>(args)...);
                    m_pInstace.store(pInstace, std::memory_order_release);
                }
            }
            return m_pInstace;
        };

        static void Destory() {
            Type * pInstace = m_pInstace.load(std::memory_order_acquire);
            delete pInstace;
            m_pInstace.store(nullptr, std::memory_order_release);
        }
    private:
        static std::atomic<Type*> m_pInstace;
        static std::mutex m_oMutex;
};

template <class Type, typename... Args> std::atomic<Type*> SingletonMutex<Type, Args...>::m_pInstace;
template <class Type, typename... Args> std::mutex SingletonMutex<Type, Args...>::m_oMutex;



template <class Type>
class SingletonStatic : public comm::NonCopyable {
    public:
        static Type* GetInstance() {
            return &m_oInstace;
        }
    private:
       static Type m_oInstace; 
};

template <class Type> Type SingletonStatic<Type>::m_oInstace;

template <class Type>
class SingletonStatic1 : public comm::NonCopyable {
    public:
        static Type* GetInstance() {
            static Type oInstace;
            return &oInstace;
        }
};


// call_once once_flag
template<class Type, typename ...Args>
class SingletonCallOnce : comm::NonCopyable {
    public:
        static Type* GetInstance(Args&&... args) {
            std::call_once(m_InitFlag, InitSingleton, std::forward<Args>(args)...);
            return m_pInstace;
        };

        static void Destory() {
            std::call_once(m_DestoryFlag, Release);
        }
    private:
        static std::once_flag m_InitFlag;
        static std::once_flag m_DestoryFlag;
        static Type* m_pInstace;

        static void InitSingleton(Args... args) {
            m_pInstace = new Type(std::forward<Args>(args)...);
        }
        
        static void Release() {
            delete m_pInstace;
            m_pInstace = nullptr;
        }
};

template<class Type, typename...Args> std::once_flag SingletonCallOnce<Type, Args...>::m_InitFlag;
template<class Type, typename...Args> std::once_flag SingletonCallOnce<Type, Args...>::m_DestoryFlag;
template<class Type, typename...Args> Type* SingletonCallOnce<Type, Args...>::m_pInstace = nullptr;

// operator new + placement new
template <class Type, typename ...Args>
class SingletonOperatorNew : comm::NonCopyable {
    public:
        static Type* GetInstance(Args&&... args) {
            if(m_pInstace == nullptr) {
                std::lock_guard<std::mutex> oLock(m_oMutex);
                if(m_pInstace == nullptr) {
                    Type* pTmp = static_cast<Type*>(operator new(sizeof(Type)));
                    new(pTmp)Type(std::forward<Args>(args)...);
                    m_pInstace = pTmp;
                }
            }
            return m_pInstace;
        };

        static void Destory() {
            std::lock_guard<std::mutex> oLock(m_oMutex);
            delete m_pInstace;
            m_pInstace = nullptr;
        }
    private:
        static Type* m_pInstace;
        static std::mutex m_oMutex;
};

template<class Type, typename...Args> Type* SingletonOperatorNew<Type, Args...>::m_pInstace = nullptr;
template<class Type, typename...Args> std::mutex SingletonOperatorNew<Type, Args...>::m_oMutex;



// barrier #define barrier() __asm__ volatile ("lwsync")
// #define barrier() __asm__ volatile ("lwsync")

// template<class Type, typename ...Args>
// class SingletonBarrier : comm::NonCopyable {
//     public:
//         static Type* GetInstance(Args&&... args) {
//             if(m_pInstace == nullptr) {
//                 std::lock_guard<std::mutex> oLock(m_oMutex);
//                 barrier();
//                 if(m_pInstace == nullptr) {
//                     m_pInstace = new Type(std::forward<Args>(args)...);
//                 }
//             }
//             return m_pInstace;
//         };

//         static void Destory() {
//             std::lock_guard<std::mutex> oLock(m_oMutex);
//             delete m_pInstace;
//             m_pInstace = nullptr;
//         }
//     private:
//         static Type* m_pInstace;
//         static std::mutex m_oMutex;
// };

// template<class Type, typename...Args> Type* SingletonBarrier<Type, Args...>::m_pInstace = nullptr;
// template<class Type, typename...Args> std::mutex SingletonBarrier<Type, Args...>::m_oMutex;


// 内存屏障
// atomic_thread_fence memory_order_acquire memory_order_release 保证他们之间的语句不会乱序执行 

template<class Type, typename ...Args>
class SingletonMemFence : comm::NonCopyable {
    public:
        static Type* GetInstance(Args&&... args) {
            Type * pInstace = m_pInstace.load(std::memory_order_relaxed);
            std::atomic_thread_fence(std::memory_order_acquire);
            if(pInstace == nullptr) {
                std::lock_guard<std::mutex> oLock(m_oMutex);
                pInstace = m_pInstace.load(std::memory_order_relaxed);
                if(m_pInstace == nullptr) {
                    pInstace = new Type(std::forward<Args>(args)...);
                    m_pInstace.store(pInstace, std::memory_order_release);
                    std::atomic_thread_fence(std::memory_order_release);
                }
            }
            return pInstace;
        };

        static void Destory() {
            std::lock_guard<std::mutex> oLock(m_oMutex);
            std::atomic_thread_fence(std::memory_order_acquire);
            Type* pInstace = m_pInstace.load(std::memory_order_relaxed);
            delete m_pInstace;
            m_pInstace.store(nullptr, std::memory_order_relaxed);
            std::atomic_thread_fence(std::memory_order_release);
        }
    private:
        static std::atomic<Type*> m_pInstace;
        static std::mutex m_oMutex;
};

template <class Type, typename... Args> std::atomic<Type*> SingletonMemFence<Type, Args...>::m_pInstace;
template <class Type, typename... Args> std::mutex SingletonMemFence<Type, Args...>::m_oMutex;



// thread_once
template<class Type>
class SingletonPthreadOnce : comm::NonCopyable {
    public:
        static Type* GetInstance() {
            pthread_once(&m_InitFlag, InitSingleton);
            return m_pInstace;
        };

        static void Destory() {
            pthread_once(&m_DestoryFlag, Destory);
        }
    private:
        static pthread_once_t m_InitFlag;
        static pthread_once_t m_DestoryFlag;
        static Type* m_pInstace;

        static void InitSingleton() {
            m_pInstace = new Type();
        }
        
        static void Release() {
            delete m_pInstace;
            m_pInstace = nullptr;
        }
};

template<class Type> pthread_once_t SingletonPthreadOnce<Type>::m_InitFlag;
template<class Type> pthread_once_t SingletonPthreadOnce<Type>::m_DestoryFlag;
template<class Type> Type* SingletonPthreadOnce<Type>::m_pInstace = nullptr;

}
