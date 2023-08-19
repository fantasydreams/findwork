#include <cstdio>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string>
#include "lib/condition/condition.h"
#include <arpa/inet.h>

#define port 9999


void scanfContinue(std::string sInfo) {
    char c;
    printf("press to %s port %d\n", sInfo.c_str(), port);
    fflush(stdout);
    scanf("%c", &c);
}

int main() {
    char c;
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    condition_true(listenfd != -1, -1, "get listen fd err %d", listenfd);

    sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    scanfContinue("bind");

    int ret = bind(listenfd, (sockaddr*)&serveraddr, sizeof(serveraddr));
    condition_true(ret == 0, -1, "bind err ret = %d\n", ret);

    scanfContinue("listen"); 

    ret = listen(listenfd, 4096);
    condition_true(ret == 0, -1, "listen err ret = %d\n", ret);

    scanfContinue("accept");

    sockaddr_in clientaddr;
    socklen_t len = sizeof(clientaddr);
    int clientfd = accept(listenfd, (sockaddr*)&clientaddr, &len);
    condition_true(clientfd != -1, -1, "accept err ret = %d", clientfd);

    // printf("client addr %s port\n", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));
    ret = getpeername(clientfd,(struct sockaddr*)&clientaddr,&len);
    condition_true(clientfd != -1, -1, "get peer name err ret = %d", ret);
    printf("peer address is %s %d\n", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port)); 

    fflush(stdout);

    scanfContinue("receive");

    unsigned char buffer[1024];
    int recvLen = recv(clientfd, buffer, 1024, 0);
    buffer[recvLen < 1024 ? recvLen : 1023] = 0;
    printf("recv msg %s, len %d\n", buffer, recvLen);
    fflush(stdout);

    scanfContinue("send");
    int writeLen = send(clientfd, buffer, recvLen, 0);
    printf("send msg %s, len %d\n", buffer, writeLen);
    fflush(stdout);

    scanfContinue("close clientfd");
    close(clientfd);

    scanfContinue("close listenfd");
    close(listenfd);

    scanfContinue("exit");
}   