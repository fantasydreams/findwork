#include <mutex>
#include <atomic>
#include <utility>
#include "no_copyable.h"

namespace comm {

// 原子变量
template <class Type, typename... Args>
class Singleton : public NonCopyable {
    public:
        static Type* GetInstance(Args&&... args) {
            if(m_pInstace == nullptr) {
                while(m_flag.test_and_set(std::memory_order_acquire)) {}
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

}