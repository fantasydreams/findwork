#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <errno.h>

int main(){

	int fd;
	extern int errno;
	if((fd = open("file.no",O_RDWR | O_CREAT)) == -1){
		printf("open err %d, %s\n",errno,strerror(errno));

	}

	if(write(fd,"1234567890",10) != 10){
		printf("write err %d, %s\n",errno,strerror(errno));
	}

	if(lseek(fd,16384,SEEK_SET) == -1){ //超出的部分根据文件系统实现会有区别，可能会分配存储空间也可能不分配存储空间
		printf("lseek err %d, %s\n",errno,strerror(errno));
	}

	if(write(fd,"1234567890",10)!= 10){
		printf("write err %d, %s\n",errno,strerror(errno));
	}

	if(close(fd) == -1){
		printf("close err %d, %s\n",errno,strerror(errno));
	}


	if((fd = open("file.no",O_RDONLY)) == -1){
		printf("open err %d\n, %s",errno,strerror(errno));
	}

	long seekEnd = lseek(fd,0,SEEK_END);
	printf("len cur %ld",seekEnd);

	if(close(fd) == -1){
		printf("close err %d, %s\n",errno,strerror(errno));
	}

	return 0;
}

// sharwen@sharwens-MacBook-Pro seek % od -c file.no 
// 0000000    1   2   3   4   5   6   7   8   9   0  \0  \0  \0  \0  \0  \0
// 0000020   \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
// *
// 0040000    1   2   3   4   5   6   7   8   9   0                        
// 0040012