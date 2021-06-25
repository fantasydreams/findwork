#include "myio.h"
#include "lib/err/myerr.h"
#include "lib/condition/condition.h"
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <fcntl.h>

int dup_fd_and_write(int fd, std::string  s_content)
{
    condition_equal( fd >= 0, true, "actual fd %d", fd);
    int _fd = dup(fd);
    int n = write(_fd, s_content.c_str(), s_content.size());
    condition_equal(n == s_content.size(), true, "write byte = %d", n);
    return true;
}


int main(int argc, char * argv[])
{
    agrc_condi(argc, 3, argv, "<fd>  <content stream>", true);
    return dup_fd_and_write(atoi(argv[1]), argv[2]);
}