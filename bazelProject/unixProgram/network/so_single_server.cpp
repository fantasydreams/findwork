#include <cstdio>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/sockio.h>
#include <netinet/in.h>
#include <stdint.h>

#include "lib/condition/condition.h"


#define port 9999
// socket 核心参数
// http://gitbook.net/html/socket/2013/0817151.html
int main(){

    // server 三个步骤
    // 1 创建一个套接字（socket）
    int fd = socket(AF_INET, SOCK_STREAM, 0); 
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
    int clientfd = accept(fd, (struct sockaddr *)&client, &len);
    printf("get clientfd %d\n", clientfd);

    unsigned char buffer[1024];
    while(true) {
        int len = recv(clientfd, (void*)buffer, 1024, 0);
        if(len == 0) {
            printf("client exit, close socket\n");
            close(clientfd);
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

    close(fd);
    return 0;
}