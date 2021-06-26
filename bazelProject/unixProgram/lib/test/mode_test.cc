#include "lib/file/mode.h"
#include "gtest/gtest.h"


TEST(mode_test_1, content)
{
    std::string mode_list = "O_CREAT | O_TRUNC | O_EXCL";
    mode_t expect = O_CREAT|O_TRUNC|O_EXCL;
    mode_t res;
    bool succ = filelib::get_mode(mode_list, res);
    EXPECT_EQ(succ, true);
    EXPECT_EQ(expect, res);
}


TEST(mode_test_2, content)
{
    std::string mode_list = "O_CREAT | O_TRUNC | O_EXCL | O_NOEXIST";
    mode_t expect = O_CREAT|O_TRUNC|O_EXCL;
    mode_t res = 0;
    bool succ = filelib::get_mode(mode_list, res);
    EXPECT_EQ(succ, false);
    EXPECT_EQ(res, expect);
}

TEST(mode_test_3, content)
{
    std::string mode_list = "S_IRWXU|S_IRUSR| S_IWUSR |S_IXUSR| S_IRWXG| S_IRWXO ";
    mode_t expect = S_IRWXU|S_IRUSR|S_IWUSR|S_IXUSR|S_IRWXG|S_IRWXO;
    mode_t res = 0;
    bool succ = filelib::get_mode(mode_list, res);
    EXPECT_EQ(succ, true);
    EXPECT_EQ(res, expect);
}

TEST(mode_test_4, content)
{
    std::string mode_list = "|S_IRUSR| S_IWUSR | S_IRWXG| S_IRWXO |||";
    mode_t expect = S_IRUSR|S_IWUSR|S_IRWXG|S_IRWXO;
    mode_t res = 0;
    bool succ = filelib::get_mode(mode_list, res);
    EXPECT_EQ(succ, true);
    EXPECT_EQ(res, expect);
}


int main(int argc, char * argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}