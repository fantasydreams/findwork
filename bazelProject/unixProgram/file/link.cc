#include "lib/err/myerr.h"
#include "lib/condition/condition.h"
#include <string>
#include <fcntl.h>
#include "lib/term/term.h"
#include <unistd.h>


int main(int argc, char * argv[])
{
    argc_condi(argc == 4, true, argv, "<create_file_pathname> <symlink pathname> <content>", true);
    std::string creat_file_pathname = argv[1];
    std::string symlink_pathname = argv[2];
    std::string w_content = argv[3];
    int fd = -1;
    
    printf("cmd: rm -rf %s\n%s", creat_file_pathname.c_str(), 
        exec_term("rm -rf " + creat_file_pathname + " " + symlink_pathname, 2048, true).c_str());
    condition_equal((fd = creat(creat_file_pathname.c_str(), O_CREAT | O_RDWR | S_IRWXU)) < 0, false, 
        "create file %s  failed", creat_file_pathname.c_str());
    condition_equal(write(fd,w_content.c_str(), w_content.size()) <= 0, false, 
        "create file %s  failed", creat_file_pathname.c_str());
    condition_equal(close(fd) < 0, false, "close file failed");

    printf("cmd: ls -ll %s\n%s", creat_file_pathname.c_str(), 
        exec_term(std::string("ls -ll ") + creat_file_pathname, 2048).c_str());
    condition_equal(symlink(("./" + creat_file_pathname).c_str(), ("./" + symlink_pathname).c_str()) < 0, 
        false, "symlink failed %s", symlink_pathname.c_str());

    printf("cmd: cat %s\n%s\n", symlink_pathname.c_str(), exec_term("cat " + symlink_pathname, 2048, true).c_str());

    printf("cmd: ls -ll %s %s\n%s", creat_file_pathname.c_str(), symlink_pathname.c_str(),
        exec_term("ls -ll " + creat_file_pathname + " " + symlink_pathname, 2048).c_str());
    
    std::string content;
    char buf[1024];
    memset(buf, 0, sizeof(buf));
    size_t size = 0;
    condition_equal((size = readlinkat(AT_FDCWD,symlink_pathname.c_str(), buf, 1024)) > 0, true, 
        "readlink failed");
    printf("symlink content:\n%s",buf);

    return 0;
}


/*
./file.txt                                                   
➜  file ./link file.txt filelink sharwentest
cmd: rm -rf file.txt
cmd: ls -ll file.txt
-rwx------  1 sharwen  wheel  11 Jun 27 23:42 file.txt
cmd: cat filelink
sharwentest
cmd: ls -ll file.txt filelink
-rwx------  1 sharwen  wheel  11 Jun 27 23:42 file.txt
lrwxr-xr-x  1 sharwen  wheel  10 Jun 27 23:42 filelink -> ./file.txt
symlink content:
./file.txt

readlink读的内容是软连接里面的内容，而不是读链接指向的文件内容，open则是读链接指向的文件内容
*/