#include "lib/err/myerr.h"
#include "lib/condition/condition.h"
#include "stat.h"
#include <iostream>

int stat_info(int argc, char * argv[])
{
    char * type_ptr = nullptr;
    struct stat buf;
    
    argc_condi(argc >= 2, true, argv, "[pathname]",true);
    for(int i = 1; i <= argc; ++i)
    {
        if(lstat(argv[i], &buf) < 0)
        {
            continue;
        }

        if(S_ISREG(buf.st_mode)){
            type_ptr = "regular";
        }else if(S_ISDIR(buf.st_mode)){
            type_ptr = "directory";
        }else if(S_ISCHR(buf.st_mode)){ //character specifial file
            type_ptr = "character special";
        }else if(S_ISBLK(buf.st_mode)){
            type_ptr = "block special";
        }else if(S_ISFIFO(buf.st_mode)){
            type_ptr = "FIFO named pipe";
        }else if(S_ISLNK(buf.st_mode)){
            type_ptr = "symbolic link";
        }else if(S_ISSOCK(buf.st_mode)){
            type_ptr = "socket";
        }else{
            type_ptr = "other type";
        }

        printf("%s\t %s\n",argv[i], type_ptr);
    }
    return 0;
}


int main(int argc, char * argv[])
{
    stat_info(argc, argv);
    return 0;
}

/*

./stat /etc /etc/ /etc/passwd /dev/null             
/etc     symbolic link
/etc/    directory
/etc/passwd      regular
/dev/null        character special

*/