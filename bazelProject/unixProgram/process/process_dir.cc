#include <unistd.h>
#include <fcntl.h>
#include "lib/term/term.h"
#include "lib/condition/condition.h"

int main(int argc, char * argv[])
{
    argc_condi(argc == 2, true, argv, "<chdir path_name>", true);
    std::string path_name = argv[1];
    printf("cmd: pwd\n%s", exec_term("pwd", 1024,true).c_str());
    condition_equal(chdir(path_name.c_str()) < 0, false , "chdir err");
    printf("cmd: pwd\n%s", exec_term("pwd", 1024,true).c_str());

    char ptr[1024];
    condition_equal(getcwd(ptr, 1024) != NULL, true, "getcwd err");
    printf("getcwd: %s", ptr);
    return 0;
}


/*
./process_chdir tmp      
cmd: pwd
/Users/sharwen/Desktop/findwork/bazelProject/unixProgram/bazel-out/darwin-fastbuild/bin/process
ret = 1 chdir err: No such file or directory


➜  process ./process_chdir /tmp
cmd: pwd
/Users/sharwen/Desktop/findwork/bazelProject/unixProgram/bazel-out/darwin-fastbuild/bin/process
cmd: pwd
/private/tmp
getcwd: /private/tmp%                                           


➜  process ./process_chdir ~/          
cmd: pwd
/Users/sharwen/Desktop/findwork/bazelProject/unixProgram/bazel-out/darwin-fastbuild/bin/process
cmd: pwd
/Users/sharwen
getcwd: /Users/sharwen

ps.
chdir只改变此进程的工作目录
*/