#include "433.MinimumGeneticMutation.h"
#include "gtest/gtest.h"

TEST(case1, content) {
    std::string startGene = "AACCGGTT", endGene = "AACCGGTA";
    std::vector<std::string> bank = {"AACCGGTA"};
    int ans = 1;
    EXPECT_EQ(minMutation(startGene, endGene, bank), ans);
}


TEST(case2, content) {
    std::string startGene = "AACCGGTT", endGene = "AAACGGTA";
    std::vector<std::string> bank = {"AACCGGTA","AACCGCTA","AAACGGTA"};
    int ans = 2;
    EXPECT_EQ(minMutation(startGene, endGene, bank), ans);
}


TEST(case3, content) {
    std::string startGene = "AACCGGTT", endGene = "AACCGGTA";
    std::vector<std::string> bank = {};
    int ans = -1;
    EXPECT_EQ(minMutation(startGene, endGene, bank), ans);
}