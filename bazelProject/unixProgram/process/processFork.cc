#include "unistd.h"
#include <iostream>


#define MAXLINE 1024

int main(){

	pid_t pid = 0;
	printf("start...\n");
	char buf[MAXLINE + 1];
	while(fgets(buf,MAXLINE,stdin) != NULL){
		if(buf[MAXLINE] != '\n'){
			buf[MAXLINE] = 0;
		}

		if((pid = fork()) < 0){
			printf("fork err");
		}
		else if(pid == 0){ // child process
			printf("print from child process id = %ld, %s\n", (long)getpid(), buf);
			execlp(buf,buf,(char*)0);
			exit(127);  //如果不加exit，则parent会进入死等
		}else{ // parent process
			printf("print from parent process id = %ld, %s\n",(long)getpid(), buf);
			int status = 0;
			if((pid = waitpid(pid,&status,0)) < 0){
				//如果这里watidpid 的 pid填0的话，就代表父进程需要等所有的子进程消亡后才会继续往下执行
				printf("waitpid err");
			} 
			printf("child process watied...\n");
		}

		printf("printf finished \n");

	}
	return 0;
}