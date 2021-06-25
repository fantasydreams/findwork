#include "test_o_append_rw.h"
#include "lib/err/myerr.h"
#include <unistd.h>
#include <cstdlib>
#include <fcntl.h>
#include "lib/condition/condition.h"

int writefiletest(int argc, char * argv[])
{
    agrc_condi(argc, 5, argv, "<filename> <seekpos> <w_content> <r_content>" , true);
    int seek_pos = atoi(argv[2]);
    std::string file_name = argv[1];
    std::string write_content = argv[3];
    std::string replace_content = argv[4];

    condition_equal(seek_pos <= write_content.size(), true, "seekpos need less equal write content's lenth");

    // int fd = creat(file_name.c_str(), O_CREAT | O_RDWR);
    // condition_equal(fd > 0, true, "create file err fd: %d", fd);
    // close(fd);

    int fd = open(file_name.c_str(), O_CREAT | O_APPEND | O_RDWR, 0644);
    condition_equal(fd > 0, true, "open file err fd: %d", fd);

    int n = write(fd, write_content.c_str(), write_content.size());
    condition_equal(n == write_content.size(), true, "write failed, write %d byte(s)", n);

    printf("write_content\n%s\n", write_content.c_str());
    off_t pos = lseek(fd, seek_pos, SEEK_SET);
    condition_equal(pos == seek_pos, true, "seek failed");

    n = write(fd, replace_content.c_str(), replace_content.size());

    char file_content[1024];
    pos = lseek(fd, 0, SEEK_SET);
    condition_equal(pos == 0, true, "seek to begin failed");
    n = read(fd, file_content, 1024);
    printf("file_content\n%s\n", file_content);

    pos = lseek(fd, seek_pos, SEEK_SET);
    condition_equal(pos == seek_pos, true, "seek to seek_pos failed");
    char r_content[1024];
    n = read(fd, r_content, 1024);
    printf("seek content\n%s\n", r_content);

    return 0;

}


int main(int argc ,char * argv[])
{
    writefiletest(argc, argv);
    return 0;
}

/*
./test_o_append test.txt 6 sharwenluo big
write_content
sharwenluo
file_content
sharwenluobig
seek content
nluobig

结论， 加了O_APPEND标志的，不能通过lseek后写，但是能通过lseek读
*/