namespace comm
{
    struct NonCopyable {
    protected:
        NonCopyable() = default;
        virtual ~NonCopyable() = default;

        NonCopyable(const NonCopyable &) = delete;
        NonCopyable &operator=(const NonCopyable &) = delete;
    };
}