#include "os_hook.h"

namespace lib
{
#ifdef __linux__
    int LibEpoll::lib_epoll_create(int size){
        return epoll_create(size);
    }

    int LibEpoll::lib_epoll_ctl(int epfd, int op, 
                    int fd, LibEpollEvent & event){
        return epoll_ctl(epfd, op, fd, event.events);
    }


    int LibEpoll::lib_epoll_wait(int epfd, LibEpollEvent & event, 
                    int max_events, int timeout){
        return epoll_wait(epfd, event.events, max_events, timeout);
    }
    
    int LibEpoll::lib_epoll_del( int epfd,int fd ){
        return 0;
    }

#elif defined(__APPLE__)
    int LibEpoll::lib_epoll_create(int size){
        return kqueue();
    }

    int LibEpoll::lib_epoll_ctl(int epfd, int op, 
                    int fd, LibEpollEvent & event){
        return 1;
    }

    int LibEpoll::lib_epoll_wait(int epfd, LibEpollEvent & event, 
                    int max_events, int timeout){
        return 1;
    }

    int LibEpoll::lib_epoll_del( int epfd,int fd ){
        return 1;
    }

#else
#error "unsupport platform"
#endif
}