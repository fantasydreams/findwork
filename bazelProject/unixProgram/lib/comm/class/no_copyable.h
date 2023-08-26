#pragma once

namespace comm
{
    struct NonCopyable { // 禁用拷贝赋值主要是两个一个是拷贝构造函数，一个是重载操作符=
    protected:
        NonCopyable() = default;
        virtual ~NonCopyable() = default;

        NonCopyable(const NonCopyable &) = delete;
        NonCopyable &operator=(const NonCopyable &) = delete;
    };
}