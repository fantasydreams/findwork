#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string>

int set_umask(mode_t mask);
int create_file(const std::string & path_name, mode_t mode);
int chmod_file(const std::string & path_name, int mode);