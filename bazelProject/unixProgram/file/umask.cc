#include "umask.h"
#include "lib/err/myerr.h"
#include "lib/condition/condition.h"
#include "lib/term/term.h"
#include "lib/file/mode.h"

int set_umask(mode_t mask)
{
    umask(mask);
    return 0;
}


int create_file(const std::string & path_name, mode_t mode)
{
    condi_eq_exit(creat(path_name.c_str(), mode) < 0, false, 
        "create file %s failed", path_name.c_str());
    return 0;
}


int chmod_file(const std::string & path_name, int mode)
{
    condi_eq_exit(chmod(path_name.c_str(), mode) < 0, false, 
        "chmod file mode %d failed", mode);
    return 0;
}


int main(int argc, char * argv[])
{
    argc_condi((argc == 7),true, argv, 
        "<create_file bool> <path_name string> <create_mode str_list> <u_mask chmod_file> <change_mode chmod_file> <max_len>", true);
    bool b_create_file = atoi(argv[1]);
    std::string path_name = argv[2];
    std::string create_mode_list = argv[3];
    std::string u_mask_list = argv[4];
    std::string change_mode_list = argv[5];
    int max_len = atoi(argv[6]);
    std::string cmd = "ls -ll " + path_name;
    
    std::string res = exec_term(cmd, max_len, true);
    printf("bofore create file\n%s", res.c_str());
    
    mode_t u_mask = 0;
    if(atoi(u_mask_list.c_str()) != 0)
    {
        condition_equal(filelib::get_mode(u_mask_list, u_mask), true, "input create_mode err, split with |");
        condition_equal(set_umask(u_mask), 0, "set umask err");
    }

    if(b_create_file)
    {
        mode_t create_mode = 0;
        condition_equal(filelib::get_mode(create_mode_list, create_mode), true, "input create_mode err, split with |");
        create_file(path_name, create_mode);
        res = exec_term(cmd, max_len);
        printf("create file \n%s", res.c_str());
    }

    mode_t change_mode = 0;
    condition_equal(filelib::get_mode(change_mode_list, change_mode), true, "input create_mode err, split with |");
    chmod_file(path_name, change_mode);
    res = exec_term(cmd, max_len);
    printf("after change mode\n %s", res.c_str());
    
    return 0;
}


/*
./umask 1 test.txt S_IRWXU 0 S_IRWXG 4096
bofore create file
ls: test.txt: No such file or directory
create file 
-rwx------  1 sharwen  wheel  0 Jun 27 14:13 test.txt
after change mode
 ----rwx---  1 sharwen  wheel  0 Jun 27 14:13 test.txt

*/
