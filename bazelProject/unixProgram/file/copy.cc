#include <fcntl.h>
#include "lib/term/term.h"
#include "lib/condition/condition.h"
#include "lib/err/myerr.h"
#include <string>

bool copy(const std::string & src, const std::string & dst)
{
    int sfd = 0, dfd = 0 , n = 0;
    condition_equal((sfd = open(src.c_str(), O_RDONLY)) < 0, false, "open %s failed\n", src.c_str());
    condition_equal((dfd = open(dst.c_str(), O_WRONLY | O_TRUNC)) < 0, false, "open %s failed\n", dst.c_str());
    char buf[1024];
    int readBytes = 0;
    int writeBytes = 0;
    
    while((n = read(sfd, buf, sizeof(buf))) != 0)
    {
        std::string wbuf = "test";
        for(int idx =0 ; idx < n; ++idx){
            if(buf[idx] != '\0'){
                wbuf += buf[idx];
            }
        }
        if(wbuf.size()){
            condition_equal( n = write(dfd, wbuf.c_str(), wbuf.size()), wbuf.size(), 
                "write file %s err\n", dst.c_str());
        }
    }
    close(sfd);
    close(dfd);
    return true;
}


int main(int argc, char * argv[])
{
    argc_condi(argc == 3, true, argv, "<source file> <destination file>", true);
    std::string cmd = "./seek " + std::string(argv[1]) + " " + argv[2];
    printf("%s\n%s", cmd.c_str(), exec_term(cmd, 4096).c_str());
    condition_equal(copy(argv[1], argv[2]) == true, true, "copy file err");
    printf("wc -c %s\n%s",argv[1], exec_term(std::string("wc -c ") + argv[1], 2048).c_str());
    printf("wc -c %s\n%s",argv[2], exec_term(std::string("wc -c ") + argv[2], 2048).c_str());
    return 0;
}


/*

./copy file.test file.copy
./seek file.test file.copy
cmd : rm -rf file.test
write hole file
len cur 16394
od -c file.test
0000000    1   2   3   4   5   6   7   8   9   0  \0  \0  \0  \0  \0  \0
0000020   \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
*
0040000    1   2   3   4   5   6   7   8   9   0                        
0040012
ls -l file.test
0000000    1   2   3   4   5   6   7   8   9   0  \0  \0  \0  \0  \0  \0
0000020   \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
*
0040000    1   2   3   4   5   6   7   8   9   0                        
0040012
du -s file.test
0000000    1   2   3   4   5   6   7   8   9   0  \0  \0  \0  \0  \0  \0
0000020   \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
*
0040000    1   2   3   4   5   6   7   8   9   0                        
0040012
wc -c file.test
0000000    1   2   3   4   5   6   7   8   9   0  \0  \0  \0  \0  \0  \0
0000020   \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
*
0040000    1   2   3   4   5   6   7   8   9   0                        
0040012
cmd : rm -rf file.copy
write real file
len cur 16394
od -c file.copy
0000000    1   2   3   4   5   6   7   8   9   0   a   a   a   a   a   a
0000020    a   a   a   a   a   a   a   a   a   a   a   a   a   a   a   a
*
0040000    1   2   3   4   5   6   7   8   9   0                        
0040012
ls -l file.copy
0000000    1   2   3   4   5   6   7   8   9   0   a   a   a   a   a   a
0000020    a   a   a   a   a   a   a   a   a   a   a   a   a   a   a   a
*
0040000    1   2   3   4   5   6   7   8   9   0                        
0040012
du -s file.copy
0000000    1   2   3   4   5   6   7   8   9   0   a   a   a   a   a   a
0000020    a   a   a   a   a   a   a   a   a   a   a   a   a   a   a   a
*
0040000    1   2   3   4   5   6   7   8   9   0                        
0040012
wc -c file.copy
0000000    1   2   3   4   5   6   7   8   9   0   a   a   a   a   a   a
0000020    a   a   a   a   a   a   a   a   a   a   a   a   a   a   a   a
*
0040000    1   2   3   4   5   6   7   8   9   0                        
0040012
wc -c file.test
   16394 file.test
wc -c file.copy
      88 file.copy

*/
