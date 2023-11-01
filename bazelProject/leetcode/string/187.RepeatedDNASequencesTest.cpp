#include "187.RepeatedDNASequences.h"
#include "gtest/gtest.h"
#include <string>

TEST(case_1, content) {
    std::string src = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    std::vector<std::string> ans = {"AAAAACCCCC","CCCCCAAAAA"};
    std::vector<std::string> res = findRepeatedDnaSequences(src);
    std::sort(ans.begin(), ans.end());
    std::sort(res.begin(), res.end());

    EXPECT_EQ(ans, res);
}


TEST(case_2, content) {
    std::string src = "AAAAAAAAAAAAA";
    std::vector<std::string> ans = {"AAAAAAAAAA"};
    std::vector<std::string> res = findRepeatedDnaSequences(src);
    std::sort(ans.begin(), ans.end());
    std::sort(res.begin(), res.end());

    EXPECT_EQ(ans, res);
}