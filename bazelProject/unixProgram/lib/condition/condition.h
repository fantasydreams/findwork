#include <unistd.h>
#include <string>
#include "lib/err/myerr.h"

#define condition_equal(exp, ret, fmt, ...) \
    {\
        int _ret = (exp); \
        if(_ret != ret) \
        {\
            std::string _fmt = std::string("ret = %d ") + fmt; \
            err_ret(_fmt.c_str(), _ret, ##__VA_ARGS__);\
            return _ret; \
        }\
    }\

#define condi_eq_exit(exp, ret, fmt, ...) \
    {\
        int _ret = (exp); \
        if(_ret != ret) \
        {\
            std::string _fmt = std::string("ret = %d ") + fmt; \
            err_exit(_ret, _fmt.c_str(), _ret, ##__VA_ARGS__);\
            return _ret; \
        }\
    }\

int argc_condi(int expr, int expect_ret, char * argv[], const std::string & para_tips, bool err_exit);