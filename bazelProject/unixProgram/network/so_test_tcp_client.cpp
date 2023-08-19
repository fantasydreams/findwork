#include <cstdio>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/signal.h>
#include <stdio.h>
#include <string>
#include <sys/sockio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <chrono>
#include "lib/condition/condition.h"
#include "lib/term/term.h"
#include <string>


#define port 9999
void scanfContinue(std::string sInfo) {
    char c;
    printf("press to %s port %d\n", sInfo.c_str(), port);
    fflush(stdout);
    scanf("%c", &c);
}


int main() {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    condition_true(fd != -1, -1, "get socket err %d", fd);

    scanfContinue("connect");

    sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    socklen_t len = sizeof(serveraddr);
    printf("%s\n", exec_term("date", 1024).c_str());
    fflush(stdout);
    std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
    int ret = connect(fd, (sockaddr *)&serveraddr,  len);
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    printf("connect cost time ms %u sec %u\n", diff.count(), diff.count() / 1000);
    fflush(stdout);

    printf("%s\n", exec_term("date", 1024).c_str());
    fflush(stdout);
    condition_true(ret == 0, -1, "connect err ret = %d", ret);


    sockaddr_in localaddr;
    socklen_t localLen = sizeof(localaddr);
    ret = getsockname(fd, (sockaddr *)&localaddr, &localLen);
    printf("conncect succ local add %s:%d\n", inet_ntoa(localaddr.sin_addr), ntohs(localaddr.sin_port));
    fflush(stdout);

    scanfContinue("send");
    std::string sBuffer = "write buffer info";

    int writeLen = send(fd, (unsigned char *)sBuffer.c_str(), sBuffer.size(), 0);
    printf("send msg %s len\n", sBuffer.c_str(), sBuffer.size());
    fflush(stdout);

    scanfContinue("recv");
    unsigned char buffer[1024];

    int recvLen = recv(fd, buffer, 1024, 0);
    printf("recv msg %s len\n", buffer, recvLen);
    fflush(stdout);

    scanfContinue("close fd");
    close(fd);

    scanfContinue("exit"); 

    return 0;
}