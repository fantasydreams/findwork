#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <sys/types.h> 
#include <sys/stat.h>
#include <errno.h> /* for definition of errno */
#include <stdarg.h> /* ISO C variable aruments */
#include "lib/err/myerr.h"
using namespace std;

// O_RDONLY , O_WRONLY, O_RDWR, O_EXEC, O_SEARCH 并不各占一位，而是0-4

void printSomeFlag()
{
    printf("O_ACCMODE hex: %d \t hex: 0x%x\n", O_ACCMODE, O_ACCMODE);
    printf("O_RDONLY  hex: %d \t hex: 0x%x\n", O_RDONLY, O_RDONLY);
    printf("O_WRONLY  hex: %d \t hex: 0x%x\n", O_WRONLY, O_WRONLY);
    printf("O_RDWR    hex: %d \t hex: 0x%x\n", O_RDWR, O_RDWR);
    printf("O_APPEND  hex: %d \t hex: 0x%x\n", O_APPEND, O_APPEND);
    printf("O_CREAT   hex: %d \t hex: 0x%x\n", O_CREAT, O_CREAT);
    printf("O_EXCL    hex: %d \t hex: 0x%x\n", O_EXCL, O_EXCL);
    printf("O_FSYNC   hex: %d \t hex: 0x%x\n", O_FSYNC, O_FSYNC);
    printf("O_SYNC    hex: %d \t hex: 0x%x\n", O_SYNC, O_SYNC);
}

int main(int argc, char * argv[])
{
    if(argc != 2)
    {
        printSomeFlag();
        err_quit("usage: ./fcntl_getfl <descriptor#>");
    }

    int val = 0;
    if((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
    {
        err_sys("fcntl err for fd %d", atoi(argv[1]));
    }

    switch (val & O_ACCMODE)
    {
    case O_RDONLY:
        printf("file is O_RDONLY\n");
        break;
    case O_WRONLY:
        printf("file is O_WRONLY\n");
        break;
    case O_RDWR:
        printf("file is O_RDWR\n");
        break;
    
    default:
        printf("file's flag is other\n");
        break;
    }

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC) 
    if(val & O_FSYNC)
    {
        printf("asynchronous writes!\n");
    }
#endif
    return 0;
}

/*
fd  0       1        2
    stdin   stdout   stderr
*/

/*
./fcntl_getfl 0 < /dev/tty
file is O_RDONLY

./fcntl_getfl 0
file is O_RDWR

./fcntl_getfl 1
file is O_RDWR

./fcntl_getfl 2
file is O_RDWR

./fcntl_getfl 1 > temp.foo
cat temp.foo   
file is O_WRONLY

./fcntl_getfl 2 >> temp.foo
file cat temp.foo   
file is O_WRONLY
file is O_RDWR



./fcntl_getfl 3 3<>temp.fo  
file is O_RDWR


./fcntl_getfl 1 &>temp.foo
file cat temp.foo              
file is O_WRONLY
*/

// 重定向符号不会算作argc argv的参数，而是直接给shell使用的

/* 几个重定向小知识
>       默认为标准输出重定向，与 1> 相同
2>&1    意思是把 标准错误输出 重定向到 标准输出.
1>&2    正确返回值传递给2输出通道 &2表示2输出通道
&>file  意思是把标准输出 和 标准错误输出 都重定向到文件file中
/dev/null是一个文件，这个文件比较特殊，所有传给它的东西它都丢弃掉。
*/