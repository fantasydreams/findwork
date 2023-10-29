#include "171.ExcelSheetColumnNumber.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    std::string str = "A";
    int ans = 1;
    EXPECT_EQ(titleToNumber(str), ans);
    EXPECT_EQ(titleToNumber1(str), ans);
}


TEST(case_2, content) {
    std::string str = "AA";
    int ans = 27;
    EXPECT_EQ(titleToNumber(str), ans);
    EXPECT_EQ(titleToNumber1(str), ans);
}


TEST(case_3, content) {
    std::string str = "Z";
    int ans = 26;
    EXPECT_EQ(titleToNumber(str), ans);
    EXPECT_EQ(titleToNumber1(str), ans);
}

TEST(case_4, content) {
    std::string str = "ZY";
    int ans = 701;
    EXPECT_EQ(titleToNumber(str), ans);
    EXPECT_EQ(titleToNumber1(str), ans);
}