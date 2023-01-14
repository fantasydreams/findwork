#include "1323.Maximum69Number.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    EXPECT_EQ(maximum69Number(9996), 9999);
}

TEST(case_2,content)
{
    EXPECT_EQ(maximum69Number(6996), 9996);
}

TEST(case_3,content)
{
    EXPECT_EQ(maximum69Number(6999), 9999);
}

TEST(case_4,content)
{
    EXPECT_EQ(maximum69Number(-9999), -6999);
}

TEST(case_5,content)
{
    EXPECT_EQ(maximum69Number(-6999), -6699);
}

TEST(case_6,content)
{
    EXPECT_EQ(maximum69Number(-6996), -6696);
}