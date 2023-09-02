#include <mutex>
#include <atomic>
#include <utility>
#include <mutex>
#include "no_copyable.h"

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


//attention 这个适合单核cpu 多线程，多核心cpu可能导致已经返回指针但是类还没有构造的情况
template <class Type, typename... Args>
class SingletonMutex :public NonCopyable {
    public:
        static Type* GetInstance(Args&&... args) {
            if(m_pInstace == nullptr) {
                std:std::lock_guard<std::mutex> oLock(m_oMutex);
                if(m_pInstace == nullptr) {
                    m_pInstace = new Type(std::forward<Args>(args)...);
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
        static std::mutex m_oMutex;
};

template <class Type, typename... Args> Type* SingletonMutex<Type, Args...>::m_pInstace = nullptr;
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

}
