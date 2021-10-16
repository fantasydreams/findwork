#include "term.h"
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>

std::string exec_term(const std::string & cmd, int max_len, bool with_err)
{
    const int max = 1024;
    std::string res;
    char buf[max];
    FILE * fp = NULL;
    std::string _cmd = with_err == false ? cmd : cmd + " 2>&1";
    fp = popen(_cmd.c_str(), "r");

    while(fgets(buf, sizeof(buf) - 1 , fp))
    {
        int n = strlen(buf);
        if(res.size() + n > max_len)
        {
            res += std::string(buf).substr(0, max_len - res.size());
            break;
        }
        res += buf;
    }
    pclose(fp);

    return  res;
}