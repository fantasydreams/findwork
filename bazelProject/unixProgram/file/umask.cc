#include "umask.h"
#include "lib/err/myerr.h"
#include "lib/condition/condition.h"
#include "lib/term/term.h"

int set_umask(mode_t mask)
{
    umask(mask);
    return 0;
}


int create_file(const std::string & path_name, mode_t mode)
{
    condi_eq_exit(creat(path_name.c_str(), mode) < 0, true, 
        "create file %s failed", path_name.c_str());
    return 0;
}


int chmod_file(const std::string & path_name, int mode)
{
    condi_eq_exit(chmod(path_name.c_str(), mode) < 0, true, 
        "chmod file mode %d failed", mode);
    return 0;
}


int main(int argc, char * argv[])
{
    argc_condi((argc == 7),true, argv, 
        "<create_file bool> <path_name str> <create_mode str_list> <u_mask chmod_file> <change_mode chmod_file> <max_len>", true);
    bool create_file = atoi(agrv[1]);
    std::string path_name = argv[2];
    mode_t create_mode = atoi(argv[3]);
    mode_t u_mask = atoi(argv[4]);
    mode_t change_mode = atoi(argv[5]);
    int max_len = atoi(argv[5]);
    std::string cmd = "ls -ll";

    if(create_file)
    {
        create_file(path_name, create_mode);
        std::string res = exec_term(cmd, max_len);
        printf("%s", res.c_str());
    }
    
    chmod_file()
    return 0;
}