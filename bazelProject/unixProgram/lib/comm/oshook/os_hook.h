#include "lib/comm/class/no_copyable.h"
#include <errno.h>
#ifdef __linux__
#include <sys/epoll.h>
#elif  defined(__APPLE__)
#include <sys/event.h>
#else
#error "platform unsupported"
#endif


#ifdef __APPLE__
    enum EPOLL_EVENTS
    {
        EPOLLIN = 0X001,
        EPOLLPRI = 0X002,
        EPOLLOUT = 0X004,

        EPOLLERR = 0X008,
        EPOLLHUP = 0X010,

        EPOLLRDNORM = 0x40,
        EPOLLWRNORM = 0x004,
    };

    #define EPOLL_CTL_ADD 1
    #define EPOLL_CTL_DEL 2
    #define EPOLL_CTL_MOD 3

    typedef union epoll_data
    {
        void *ptr;
        int fd;
        uint32_t u32;
        uint64_t u64;

    } epoll_data_t;

    struct epoll_event
    {
        uint32_t events;
        epoll_data_t data;
    };

#endif

namespace lib
{

    class LibEpollEvent
    {
    public:
        LibEpollEvent():size(0), events(nullptr), event_list(nullptr){};
        ~LibEpollEvent() = default;

        int size;
        epoll_event *events;
        struct kevent *event_list;
    };

    class LibEpoll : private comm::NonCopyable
    {
        LibEpoll();
        ~LibEpoll();

    public:
        int lib_epoll_create(int size);
        int lib_epoll_ctl(int epfd, int op, int fd, LibEpollEvent & event);
        int lib_epoll_wait(int epfd, LibEpollEvent & event, int max_events, int timeout);

    private:
        int lib_epoll_del(int epfd,int fd);
    };
}