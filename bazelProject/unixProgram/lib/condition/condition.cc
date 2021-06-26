#include "condition.h"
#include "lib/err/myerr.h"

int argc_condi(int expr, int expect_ret, char * argv[], const std::string & para_tips, bool err_exit)
{
    if(expr != expect_ret)
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