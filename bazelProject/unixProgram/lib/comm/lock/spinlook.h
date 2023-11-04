#include <atomic>
#include <pthread.h>
#include <atomic>
#include <signal.h>
#include "lib/comm/class/no_copyable.h"
#include "lib/comm/class/exception.h"

#ifdef __APPLE__
#include <os/lock.h>
#endif

// std::atomic_flag m_flag.test_and_set(std::memory_order_acquire) 和 m_flag.clear(std::memory_order_release)结合可以当做一个简单的自旋锁
// 在上锁的时候，如果 m_flag.test_and_set 返回 false，则表示上锁成功（此时 while 不会进入自旋状态），因为此前 m_flag 的标志位为 false(即没有线程对 lock 进行上锁操作)，但调用 test_and_set 后 lock 的标志位为 true，说明某一线程已经成功获得了 lock 锁。
// 原子变量
class SpinLockAtomic : public comm::NonCopyable{
public:
    SpinLockAtomic() : m_lock (ATOMIC_FLAG_INIT) { }
    virtual ~SpinLockAtomic() {}
    void Lock() {
        while(m_lock.test_and_set(std::memory_order_acquire)) { 
        }
    }

    void UnLock() {
        m_lock.clear(std::memory_order_release);
    }

private:
    std::atomic_flag m_lock;
};

// class SpinLockAtomic : public NonCopyable{
// public:
//     SpinLockAtomic() : m_lock (ATOMIC_FLAG_INIT) { }
//     virtual ~SpinLockAtomic() {}
//     Lock() {
//         while(m_lock.test_and_set(std::memory_order_seq_cst)) { 
//         }
//     }

//     UnLock() {
//         while(m_lock.clear(std::memory_order_seq_cst)) {
//         }
//     }

// private:
//     std::atomic_flag m_lock;
// };



class SpinLock : public comm::NonCopyable{
public:

#ifndef __APPLE__
    SpinLock() {
        if(pthread_spin_init(&m_oSpinLock, 0)) {
            throw SysCallException(errno, "pthread_spin_init error");
        } 
    }

    ~SpinLock() {
        pthread_spin_destroy(&m_oSpinLock);
    }

    void Lock() {
        if(pthread_spin_lock(&m_oSpinLock)) {
            throw SysCallException(errno, "pthread_spin_lock error");
        }
    }

    bool TryLock() {
        int iRet = pthread_spin_trylock(&m_oSpinLock);
        if(iRet) {
            if(iRet == EBUSY) {
                return false;
            }
            throw SysCallException(errno, "pthread_spin_trylock error");
        }
        return true;
    }

    void UnLock() {
        if(pthread_spin_unlock(&m_oSpinLock)) {
            throw SysCallException(errno, "pthread_spin_unlock error");
        }
    }
#else 
    SpinLock() : m_oSpinLock(os_unfair_lock()) { }

    ~SpinLock() {}
    void Lock() {
        os_unfair_lock_lock(&m_oSpinLock);
    }
    bool TryLock() {
        return os_unfair_lock_trylock(&m_oSpinLock);
    }
    void UnLock() {
        os_unfair_lock_unlock(&m_oSpinLock);
    }
#endif
private:

#ifndef __APPLE__
    pthread_spinlock_t m_oSpinLock;
#else 
    os_unfair_lock m_oSpinLock;
#endif
};


class ScopeSpinLockAtomic {
public:
    explicit ScopeSpinLockAtomic(SpinLockAtomic & oSpinLock) : m_oSpinLock(oSpinLock) {
        m_oSpinLock.Lock(); 
    } 

    ~ScopeSpinLockAtomic() {
        m_oSpinLock.UnLock();
    }

private:
    SpinLockAtomic& m_oSpinLock;
};