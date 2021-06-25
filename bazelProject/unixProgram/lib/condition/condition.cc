#include "condition.h"
#include "lib/err/myerr.h"

int agrc_condi(int argc, int num, char * argv[], const std::string & para_tips, bool err_exit)
{
    if(argc != num)
    {
        if(err_exit)
        {
            err_quit("usage: %s %s",argv[0], para_tips.c_str());
        }else
        {
            printf("usage: %s %s",argv[0],  para_tips.c_str());
        }
        return false;
    }
    return true;
}