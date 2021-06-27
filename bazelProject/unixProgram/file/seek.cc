#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <errno.h>
#include "lib/term/term.h"

void writeHoleFile()
{
	int fd;
	extern int errno;
	printf("write hole file\n");
	if((fd = open("file.no",O_CREAT | O_RDWR, 0644)) == -1){
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
	printf("len cur %ld\n",seekEnd);

	if(close(fd) == -1){
		printf("close err %d, %s\n",errno,strerror(errno));
	}

	
	printf("%s\n%s","od -c file.no", exec_term("od -c file.no", 2048).c_str());
	printf("%s\n%s","ls -l file.no", exec_term("ls -l file.no", 2048).c_str());
	printf("%s\n%s","du -s file.no", exec_term("du -s file.no", 2048).c_str());
	printf("%s\n%s","wc -c file.no", exec_term("wc -c file.no", 2048).c_str());

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
	printf("write real file\n");
	if((fd = open("file1.no",O_RDWR | O_CREAT, 0644)) == -1){
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
	printf("len cur %ld\n",seekEnd);

	if(close(fd) == -1){
		printf("close err %d, %s\n",errno,strerror(errno));
	}

	printf("%s\n%s","od -c file1.no", exec_term("od -c file1.no", 2048).c_str());
	printf("%s\n%s","ls -l file1.no", exec_term("ls -l file1.no", 2048).c_str());
	printf("%s\n%s","du -s file1.no", exec_term("du -s file1.no", 2048).c_str());
	printf("%s\n%s","wc -c file1.no", exec_term("wc -c file1.no", 2048).c_str());
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

	printf("%s\n%s","rm -rf file*", exec_term("rm -rf file*", 2048).c_str());
	writeHoleFile();
	writeRealFile();

	return 0;
}

/*
./seek          
rm -rf file*
write hole file
len cur 16394
od -c file.no
0000000    1   2   3   4   5   6   7   8   9   0  \0  \0  \0  \0  \0  \0
0000020   \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
*
0040000    1   2   3   4   5   6   7   8   9   0                        
0040012
ls -l file.no
-rw-r--r--  1 sharwen  wheel  16394 Jun 27 19:42 file.no
du -s file.no
40      file.no
wc -c file.no
   16394 file.no
write real file
len cur 16394
od -c file1.no
0000000    1   2   3   4   5   6   7   8   9   0   a   a   a   a   a   a
0000020    a   a   a   a   a   a   a   a   a   a   a   a   a   a   a   a
*
0040000    1   2   3   4   5   6   7   8   9   0                        
0040012
ls -l file1.no
-rw-r--r--  1 sharwen  wheel  16394 Jun 27 19:42 file1.no
du -s file1.no
40      file1.no
wc -c file1.no
   16394 file1.no
*/