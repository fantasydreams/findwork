#include <unistd.h>
#include <errno.h>
#include <stdarg.h>
#include <fcntl.h>


//set fd's flag as | flag
int set_file_flag(int fd, int flag);