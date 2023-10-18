#include <cassert>
#include <cstddef>
#include <stdio.h>
#include <iostream>
#include <sys/socket.h>
#include <sys/signal.h>
#include <signal.h>
#include <netinet/in.h>
#include <system_error>
#include <unistd.h>
#include <sys/poll.h>
#include <assert.h>
#include "lib/condition/condition.h"
#include "lib/err/myerr.h"
#include <vector>
#include <sys/epoll.h>
#include <unordered_map>
#include <algorithm>


#define backlog 1024
#define pollsize 1024
#define port 9999
int bRun = true;
void SignalStop(int signal) {
    std::cout << "signal recive stop " << signal << std::endl;
    bRun = false;
}

void SignalHander(void) {
    assert(signal(SIGFPE, SIG_IGN) != SIG_ERR);
    assert(signal(SIGCHLD, SIG_IGN) != SIG_ERR);
    assert(signal(SIGALRM, SIG_IGN) != SIG_ERR);

    assert(sigset(SIGINT, SignalStop) != SIG_ERR);
    assert(sigset(SIGQUIT, SignalStop) != SIG_ERR); 
    assert(sigset(SIGTERM, SignalStop) != SIG_ERR);
    assert(sigset(SIGUSR1, SignalStop) != SIG_ERR);
}

const static epoll_event EMPTY_EVENT = { 0, { 0 } };

int main() {
    SignalHander();
    sockaddr_in s_addr;
    s_addr.sin_family = AF_INET;
    s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    s_addr.sin_port = htons(port);

    int bfd = socket(AF_INET, SOCK_STREAM, 0);
    condition_true(bfd != -1, -1, "get socket fd err ret = %d", bfd);

    int ret = bind(bfd, (struct sockaddr *)&s_addr, sizeof(s_addr));
    condition_true(ret != -1, -1, "bind err ret = %d", ret);

    ret = listen(bfd, backlog);
    condition_true(ret != -1, -1, "listen err ret = %d", bfd);

    struct epoll_event ev;
    std::vector<struct epoll_event> events(32, EMPTY_EVENT);
    ev.events = EPOLLIN;
    ev.data.fd = bfd;

    auto epollfd = epoll_create(1);
    if(epollfd == -1) {
        std::cerr << "create epoll err " << epollfd << std::endl;
        close(bfd);
        return -1;
    } 

    if(epoll_ctl(epollfd, EPOLL_CTL_ADD, bfd, &ev) == -1) {
        std::cerr << "ctl epoll err " << epollfd << std::endl;
        close(bfd);
        return -1;
    }

    std::unordered_map<int, std::string> hashData;
    std::cout << "runing..." << std::endl;
    while(bRun) {
        int nfds = epoll_wait(epollfd, (struct epoll_event*)&events[0], static_cast<int>(events.size()), 1000);
        // std::cout << "get ready fds" << nfds << std::endl;
        for(int i = 0; i < nfds; ++i) {
            // std::cout << "loop" << events.size() << std::endl;
            if(events[i].events) {
                if(events[i].data.fd == bfd) {
                    if(events[i].events & EPOLLIN) {
                        std::cout << "start accpet connect..." << std::endl;
                        sockaddr_in addr;
                        socklen_t len = sizeof(addr);
                        int clientfd = accept(events[i].data.fd, (struct sockaddr*)&addr, &len);
                        if(clientfd == -1) {
                            std::cerr << "get clientfd err"<< std::endl;
                        }else {
                            std::cout << "get connect client" << clientfd << std::endl;
                            ev.events = EPOLLIN | EPOLLET;
                            ev.data.fd = clientfd;
                            if(epoll_ctl(epollfd, EPOLL_CTL_ADD, clientfd, &ev) == -1) {
                                std::cerr << "ctl epoll err " << clientfd << std::endl;
                            }
                        }
                    }
                }else{
                    if(events[i].events & EPOLLIN) {
                        unsigned char buffer[2048];
                        int len = recv(events[i].data.fd, buffer, 2048, 0);
                        if(len == 0) {
                            int ret = epoll_ctl(epollfd, EPOLL_CTL_DEL, events[i].data.fd, NULL);
                            std::cout << "client close " << events[i].data.fd << std::endl;
                            close(events[i].data.fd);
                        }else if(len > 0){
                            len = len >= 2048 ? 2047 : len;
                            buffer[len] = 0;
                            hashData[events[i].data.fd] = std::string((char*)buffer);

                            ev.data.fd = events[i].data.fd;
                            ev.events = EPOLLOUT;
                            if(epoll_ctl(epollfd, EPOLL_CTL_MOD, events[i].data.fd, &ev) == -1) {
                                std::cerr << "mod err " << events[i].data.fd << std::endl; 
                            }
                        }else {
                            std::cerr<< "recive err" << std::endl;
                        }
                    }

                    if(events[i].events & EPOLLOUT){
                        auto pIter = hashData.find(events[i].data.fd);
                        if(pIter != hashData.end()) {
                            int len = send(events[i].data.fd, pIter->second.c_str(), pIter->second.size(), 0);
                            std::cout << "send to client " << events[i].data.fd << "len " << len << std::endl;

                            ev.data.fd = events[i].data.fd;
                            ev.events = EPOLLIN;
                            if(epoll_ctl(epollfd, EPOLL_CTL_MOD, events[i].data.fd, &ev) == -1) {
                                std::cerr << "mod err " << events[i].data.fd << std::endl; 
                            }
                        }
                    }
                }
            }

            if(nfds > events.size()) { // 自动扩容
                events.insert(events.end(), std::min(2 * nfds, pollsize), EMPTY_EVENT);
            }
        }
    }

    close(bfd);

    return 0;
}