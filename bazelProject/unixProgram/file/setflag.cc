#include "lib/file/myfcntl.h"
#include "lib/err/myerr.h"

int main(int argc, char * argv[])
{
    if(argc != 3)
    {
        err_quit("usage: %s <descriptor> <flag>", argv[0]);
    }
    int flag = atoi(argv[2]);

    int old_flag = 0;
    if((old_flag = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
    {
        err_quit("get file flag err\n");
    }

    printf("before set flag ,old_flag %d",old_flag);
    int ret = set_file_flag(atoi(argv[1]), flag);

    if(ret == 0)
    {
        printf("set flag sucess\n");
    }else
    {
        err_msg("set flag failed with ret = %d\n", ret);
    }

    int new_flag = 0;
    if((new_flag = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
    {
        err_quit("get file flag err\n");
    }
    printf("after set flag ,new_flag %d",new_flag);
    return 0;
}