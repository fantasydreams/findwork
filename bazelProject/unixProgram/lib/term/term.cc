#include "term.h"
#include <stdio.h>
#include <cstdlib>
#include <cstring>

std::string exec_term(const std::string & cmd, int max_len)
{
    const int max = 1024;
    std::string res;
    char buf[max];
    FILE * fp = NULL;
    fp = popen(cmd.c_str(), "r");
    while(fgets(buf, sizeof(buf) - 1 , fp))
    {
        int n = strlen(buf);
        if(res.size() + n >= max_len){
            res += std::string(buf).substr(0, max_len - res.size());
            break;
        }
        res += buf;
    }

    return  res;
}