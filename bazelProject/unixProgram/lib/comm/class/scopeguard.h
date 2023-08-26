#pragma once

#include "no_copyable.h"
#include <functional>
#include <utility>


namespace comm {
    class ScopeGuard : public NonCopyable {
        public:
            ScopeGuard() = delete;
            explicit ScopeGuard(std::function<void()> onExit, 
                std::function<bool()> active = [](){return true;}) :m_fOnExit(onExit), m_fActive(active) {};

            ~ScopeGuard() {
                if(m_fActive()) {
                    m_fOnExit();
                }
            }
        private:
            std::function<void()> m_fOnExit;
            std::function<bool()> m_fActive;
    };

    
    template <typename Func>
    class ScopeGuard1 : public NonCopyable {
        public:
            ScopeGuard1() = delete;
            ScopeGuard1(Func && f) : m_func(std::forward<Func>(f)), m_active(true) {};
            ScopeGuard1(ScopeGuard1<Func> && oRScopeGuard) : m_func(std::move(oRScopeGuard.m_func)), m_active(oRScopeGuard.m_active) {oRScopeGuard.Cancle();};
            ~ScopeGuard1() { if(m_active) {m_func();} }

            void Cancle() {m_active = false;};
        private:
            Func m_func;
            bool m_active;
    };

    enum class ScopeGuard1NeumClassHelper {
    };

    template <typename Func>
    inline ScopeGuard1<Func> operator+(ScopeGuard1NeumClassHelper, Func && f) {
        return ScopeGuard1<Func>(std::forward<Func>(f));
    }
}

#define __SCOPEGUARD_HELPER_IMPL(s1, s2) s1##_##s2
#define __SCOPEGUARD_HELPER(s1, s2) __SCOPEGUARD_HELPER_IMPL(s1, s2)
#define ON_SCOPT_EXIT auto __SCOPEGUARD_HELPER(RAII_AT_EXIT, __LINE__) = comm::ScopeGuard1NeumClassHelper() + [&]()
#define ON_SCOPE_EXIT_WITH_RETURN comm::ScopeGuard1NeumClassHelper() + [&]()
// https://www.cnblogs.com/chenny7/p/11990105.html
