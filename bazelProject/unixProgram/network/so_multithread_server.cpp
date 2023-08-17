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

#include "lib/condition/condition.h"

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
    while(!setThreadIs.empty()) {
        std::cerr << "some thread run.. sleep" << std::endl;
        sleep(1);
    }

    close(fd);
    std::cerr << "exit... finished" << std::endl;
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



void *thread_routine (void * args) {
    int clientfd = *((int*)args);
    unsigned char buffer[1024];

    bool bclose = false;
    while(bRun) {
        int len = recv(clientfd, (void*)buffer, 1024, 0);
        if(len == 0) {
            printf("client exit, close socket threadid: %ull\n", pthread_self());
            close(clientfd);
            bclose = true;
            break;
        }

        if(len < 1024) {
            buffer[len] = 0;
        }else {
            buffer[1023] = 0;
        }
        printf("reviced data: %s\n", buffer);
        fflush(stdout);

        len = send(clientfd, (void*)buffer, len, 0);
    }
    if(!bclose) {
        close(clientfd);
    }
    setThreadIs.erase(pthread_self());
    return 0;   
}

int main(){

    //注册一个handler
    SignalHandler();

    // server 三个步骤
    // 1 创建一个套接字（socket）
    fd = socket(AF_INET, SOCK_STREAM, 0); 
    condition_equal(fd != -1, true, "get fd err: %d", fd);

    struct sockaddr_in server_addr;
    server_addr.sin_family  = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);


    // 2 绑定套接字地址套端口
    int ret = bind(fd, (const struct sockaddr*)&server_addr, sizeof(server_addr));
    condition_equal(ret != -1, true, "bind err, ret = %d", ret);

    // 3 监听

    ret = listen(fd, 4096);
    condition_equal(ret != -1, true, "listen err, ret = %d", ret);
    
    printf("listen...\n");

    sockaddr_in client;
    socklen_t len = sizeof(client);
    while(bRun) {

        int clientfd = accept(fd, (struct sockaddr *)&client, &len);
        printf("get clientfd %d\n", clientfd);
        condition_equal(clientfd != -1, true, "get client err");

        pthread_t tid = 0;
        ret = pthread_create(&tid, NULL, thread_routine, (void*)&clientfd);
        setThreadIs.insert(tid);
        pthread_detach(tid);
    }

    close(fd);
    return 0;
}