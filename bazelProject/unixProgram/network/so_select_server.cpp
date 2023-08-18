#include <cstddef>
#include <cstdio>
#include <ostream>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/sockio.h>
#include <netinet/in.h>
#include <stdint.h>
#include <iostream>
#include <set>
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <signal.h>
#include <string.h>

#include "lib/condition/condition.h"
#include "lib/err/myerr.h"

#define port 9999
// socket 核心参数
// http://gitbook.net/html/socket/2013/0817151.html

bool bRun = true;
std::set<pthread_t> setThreadIs;

int fd = -1;

void SignalStop ( int singel )
{
    std::cerr << "stop signal received" << singel << std::endl;
    bRun = false;
}


void SignalHandler ( void )
{
    assert ( signal ( SIGPIPE, SIG_IGN ) != SIG_ERR ) ;
    assert ( signal ( SIGALRM, SIG_IGN ) != SIG_ERR ) ;
    assert ( signal ( SIGCHLD, SIG_IGN ) != SIG_ERR ) ;

    assert ( sigset ( SIGINT, SignalStop ) != SIG_ERR ) ;
    assert ( sigset ( SIGTERM, SignalStop ) != SIG_ERR ) ;
    assert ( sigset ( SIGHUP, SignalStop ) != SIG_ERR ) ;
    assert ( sigset ( SIGUSR1, SignalStop ) != SIG_ERR ) ;
}

#define port 9999

int main() {
    SignalHandler();

    std::set<int> fdSet;

    fd = socket(AF_INET, SOCK_STREAM, 0);
    condition_true(fd != -1, -1, "get socket fd err");
    fdSet.insert(fd);

    sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    int ret = bind(fd, (sockaddr*)&serveraddr, sizeof(serveraddr));
    condition_true(ret == 0, ret, "bind err ret = %d", ret);

    ret =listen(fd, 4096); // listen 核心参数，第二个参数为backlog等待队列
    condition_true(ret != -1, ret, "listen err ret = %d", ret);
    printf("start listen...\n");

    int maxfd = fd;
    fd_set rfds, wfds;
    FD_ZERO(&rfds);
    FD_ZERO(&wfds);
    FD_SET(fd, &rfds); //表示这个fd要进行监听检测是否有事件，这里只是表示要检测是否有读事件

    unsigned char buffer[1024];

    struct timeval t;
    t.tv_sec = 1;
    while(bRun) {
        fd_set rset = rfds, wset = wfds;
        int ready = select(maxfd + 1, &rset, &wset, nullptr, nullptr);
        if(ready <= 0) {
            continue;
        }

        for(int i = 0 ;i <= maxfd; ++i) {
            if(i == fd) {
                if(FD_ISSET(fd, &rset)) {
                    sockaddr_in clientaddr;
                    socklen_t len = sizeof(clientaddr);
                    int clientfd = accept(fd, (sockaddr *)&clientaddr, &len);
                    if(clientfd == -1) {
                        err_msg("accept err fd: %d", clientfd);
                    }else {
                        printf("get client fd %d \n", clientfd);
                        if(maxfd < clientfd) {
                            maxfd = clientfd;
                        }
                        FD_SET(clientfd, &rfds); // 设置关注可读事件
                        fdSet.insert(clientfd);
                    }
                }
            }else {
                if(FD_ISSET(i, &rset)) {
                    int readLen = recv(i, buffer, 1024, 0);
                    if(readLen == 0) {
                        FD_CLR(i, &rfds);
                        printf("client close client fd %d\n", i);
                        fflush(stdout);
                        close(i);
                        fdSet.erase(i);
                    }else {
                        buffer[readLen < 1024 ? readLen : 1023] = 0;
                        printf("revice client %d msg: %s\n", i, buffer);
                        FD_SET(i, &wfds); // 设置关注可写事件
                        fflush(stdout);
                    }
                }

                if(FD_ISSET(i, &wset)) {
                    int writeLen = send(i, buffer, (size_t)strlen((const char *)buffer), 0);
                    printf("send to client %d msg: %s\n", i, buffer);
                    fflush(stdout);
                    FD_CLR(i, &wfds); // 清除关注可写事件
                }
            }
        }
    }

    

    for(const auto & fd : fdSet) {
        close(fd);
    }
    std::cerr << "exit... finished" << std::endl;
    return 0;
}