#include "49.GroupAnagrams.h"

#include "gtest/gtest.h"
#include <string>
#include <vector>

TEST(case_1, content)
{
    std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};
    std::vector<std::vector<std::string>> ans = {{"bat"},{"nat","tan"},{"ate","eat","tea"}};
    std::vector<std::vector<std::string>> res = groupAnagrams(strs); 
    std::sort(strs.begin(), strs.end());
    for(auto & vec : res) {
        sort(vec.begin(), vec.end());
    }

    EXPECT_EQ(res, ans);
}


TEST(case_2, content)
{
    std::vector<std::string> strs = {""};
    std::vector<std::vector<std::string>> ans = {{""}};
    std::vector<std::vector<std::string>> res = groupAnagrams(strs); 
    std::sort(strs.begin(), strs.end());
    for(auto & vec : res) {
        sort(vec.begin(), vec.end());
    }
    EXPECT_EQ(res, ans);
}


TEST(case_3, content)
{
    std::vector<std::string> strs = {"a"};
    std::vector<std::vector<std::string>> ans = {{"a"}};
    std::vector<std::vector<std::string>> res = groupAnagrams(strs); 
    std::sort(strs.begin(), strs.end());
    for(auto & vec : res) {
        sort(vec.begin(), vec.end());
    }
    EXPECT_EQ(res, ans);
}


TEST(case_21, content)
{
    std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};
    std::vector<std::vector<std::string>> ans = {{"bat"},{"nat","tan"},{"ate","eat","tea"}};
    std::vector<std::vector<std::string>> res = groupAnagrams1(strs); 
    std::sort(strs.begin(), strs.end());
    for(auto & vec : res) {
        sort(vec.begin(), vec.end());
    }

    EXPECT_EQ(res, ans);
}


TEST(case_22, content)
{
    std::vector<std::string> strs = {""};
    std::vector<std::vector<std::string>> ans = {{""}};
    std::vector<std::vector<std::string>> res = groupAnagrams1(strs); 
    std::sort(strs.begin(), strs.end());
    for(auto & vec : res) {
        sort(vec.begin(), vec.end());
    }
    EXPECT_EQ(res, ans);
}


TEST(case_23, content)
{
    std::vector<std::string> strs = {"a"};
    std::vector<std::vector<std::string>> ans = {{"a"}};
    std::vector<std::vector<std::string>> res = groupAnagrams1(strs); 
    std::sort(strs.begin(), strs.end());
    for(auto & vec : res) {
        sort(vec.begin(), vec.end());
    }
    EXPECT_EQ(res, ans);
}