#include <ostream>
#include <stdio.h>
#include <string>
#include <string_view>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/poll.h>
#include "lib/condition/condition.h"
#include "lib/err/myerr.h"
#include <sys/signal.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/types.h>
#include <cstddef>
#include <assert.h>
#include <iostream>
#include <sys/signal.h>
#include <signal.h>
#include <unordered_map>
#include <string>

#define port 9999
#define backlog 1024
// 这里要注意linux ulimit -a能打开文件的最大数量，超过这么多poll会报错 invalid arguments
#define pollsize 1024
int bRun = true;

void SignalStop(int signal) {
    std::cerr << "revice signal :" << signal << std::endl << "stop server";
    bRun = false;
}

void SignalHandler(void) {
    assert ( signal ( SIGPIPE, SIG_IGN ) != SIG_ERR ) ;
    assert ( signal ( SIGALRM, SIG_IGN ) != SIG_ERR ) ;
    assert ( signal ( SIGCHLD, SIG_IGN ) != SIG_ERR ) ;

    assert ( sigset ( SIGINT, SignalStop ) != SIG_ERR ) ;
    assert ( sigset ( SIGTERM, SignalStop ) != SIG_ERR ) ;
    assert ( sigset ( SIGHUP, SignalStop ) != SIG_ERR ) ;
    assert ( sigset ( SIGUSR1, SignalStop ) != SIG_ERR ) ;
}

int main() {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    condition_true(fd != -1, -1, "get socket fd err");
    sockaddr_in s_addr;
    s_addr.sin_family = AF_INET;
    s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    s_addr.sin_port = htons(port);

    int ret = bind(fd, (struct sockaddr*)&s_addr, sizeof(s_addr));
    condition_true(ret == 0, -1, "bind addr err ret = %d", ret);

    ret = listen(fd, backlog);
    condition_true(ret == 0, -1, "listen addr err ret = %d", ret);

    std::unordered_map<int, std::string> hashData;

    struct pollfd fds[pollsize] = {};
    fds[fd].fd = fd;
    fds[fd].events = POLL_IN;

    std::cout <<"start runing..." << std::endl;

    while(bRun) {
        std::cout << "in while..." << std::endl;
        int ready = poll(fds, pollsize, 1000);
        if(ready == 0) {
            std::cout << "no ready fd..." << std::endl;
            continue;
        }else if(ready == -1) {
            perror("poll");
            continue;
        }

        std::cout << "poll return.." << ready << std::endl;

        for(int i = 0; i < pollsize; ++i) {
            if(fds[i].revents) {
                if(fds[i].fd == fd) {
                    if(fds[i].revents & POLL_IN) {
                        sockaddr_in addr;
                        socklen_t len = sizeof(addr);
                        int clientfd = accept(fd, (struct sockaddr*)&addr, &len);
                        fds[clientfd].fd = clientfd;
                        fds[clientfd].events = POLL_IN;

                        std::cout << "get client" << clientfd << std::endl ;
                    }
                }else {
                    if(fds[i].revents | POLL_IN) {
                        unsigned char buffer[2048];
                        int len = recv(fds[i].fd, buffer, 2048, 0);
                        if(len == 0) {
                            std::cout << "client " << fds[i].fd << " closed" << std::endl;
                            fds[i].fd = -1;
                            fds[i].events = 0;
                            close(fds[i].fd);
                        }else if(len > 0) {
                            buffer[len == 1024 ? 1023 : len] = 0;
                            hashData[fds[i].fd] = std::string((char *)buffer);
                            fds[i].events = POLL_OUT;

                            std::cout << "recive from client " << fds[i].fd << "msg : " << buffer << "len " << len << std::endl;
                        }else {
                            std::cerr << "get err" << fds[i].fd << "len " << len << std::endl;
                        }
                    }

                    if(fds[i].revents | POLL_OUT) {
                        auto pIter = hashData.find(fds[i].fd);
                        if(pIter != hashData.end() && pIter->second.size()) {
                            int res = send(fds[i].fd, (void *)pIter->second.c_str(), pIter->second.size(), 0);
                            std::cout << "send to client" << fds[i].fd << "msg: " << pIter->second << "send size " << res << std::endl ;
                        }
                        fds[i].events = POLL_IN;
                    }
                }
            }
        }
    }

    close(fd);

    return 0;
}