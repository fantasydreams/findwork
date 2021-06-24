#include "lib/file/myfcntl.h"
#include "lib/err/myerr.h"

int set_file_flag(int fd, int flags)
{
    int old_flag = 0;
    if((old_flag = fcntl(fd, F_GETFL, 0)) < 0)
    {
        err_sys_printf_noly("get fd flag err\n");
        return old_flag;
    }
    
    int new_flag = old_flag | flags;
    if((old_flag = fcntl(fd, F_SETFL, new_flag)) < 0)
    {
        err_sys_printf_noly("set fd flag err");
        return old_flag;
    }

    return 0;
}