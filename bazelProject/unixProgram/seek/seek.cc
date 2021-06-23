#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <errno.h>

void writeHoleFile()
{
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
}
// sharwen@sharwens-MacBook-Pro seek % od -c file.no 
// 0000000    1   2   3   4   5   6   7   8   9   0  \0  \0  \0  \0  \0  \0
// 0000020   \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
// *
// 0040000    1   2   3   4   5   6   7   8   9   0                        
// 0040012

void writeRealFile()
{
	int fd;
	extern int errno;
	if((fd = open("file1.no",O_RDWR | O_CREAT)) == -1){
		printf("open err %d, %s\n",errno,strerror(errno));

	}

	if(write(fd,"1234567890",10) != 10){
		printf("write err %d, %s\n",errno,strerror(errno));
	}

	// if(lseek(fd,16384,SEEK_SET) == -1){ //超出的部分根据文件系统实现会有区别，可能会分配存储空间也可能不分配存储空间
	// 	printf("lseek err %d, %s\n",errno,strerror(errno));
	// }

	int fileSek = lseek(fd,0,SEEK_CUR);
	while(fileSek++ < 16384){
		if(write(fd,"a",1)!= 1){
			printf("write err %d, %s\n",errno,strerror(errno));
		}
	}


	if(write(fd,"1234567890",10)!= 10){
		printf("write err %d, %s\n",errno,strerror(errno));
	}

	if(close(fd) == -1){
		printf("close err %d, %s\n",errno,strerror(errno));
	}


	if((fd = open("file1.no",O_RDONLY)) == -1){
		printf("open err %d\n, %s",errno,strerror(errno));
	}

	long seekEnd = lseek(fd,0,SEEK_END);
	printf("len cur %ld",seekEnd);

	if(close(fd) == -1){
		printf("close err %d, %s\n",errno,strerror(errno));
	}
}

/*
➜  seek od -c file1.no
0000000    1   2   3   4   5   6   7   8   9   0   a   a   a   a   a   a
0000020    a   a   a   a   a   a   a   a   a   a   a   a   a   a   a   a
*
0040000    1   2   3   4   5   6   7   8   9   0                        
0040012
*/

int main(){

	writeHoleFile();
	writeRealFile();

	return 0;
}

/*
➜  seek ls -ls file.no file1.no 
40 -rw-r--r--  1 sharwen  wheel  16394 Jun 24 00:50 file.no
40 -rw-r--r--  1 sharwen  wheel  16394 Jun 24 00:50 file1.no
*/

//mac在系统中，固态硬盘测试结果如上，可能在其他的系统如机械硬盘中，占据的盘块可能不一致
