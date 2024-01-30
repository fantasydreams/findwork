#include "68.TextJustification.h"
#include "gtest/gtest.h"
#include <vector>
#include <cstdlib>
#include <cmath>



TEST(case_1, content)
{
    std::vector<std::string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    std::vector<std::string> ans = {
        "This    is    an",
        "example  of text",
        "justification.  "
    };
    int maxWidth = 16;
    
    EXPECT_EQ(fullJustify(words, maxWidth), ans);
    EXPECT_EQ(fullJustify1(words, maxWidth), ans);
}


TEST(case_2, content)
{
    std::vector<std::string> words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    std::vector<std::string> ans = {
        "Science  is  what we",
        "understand      well",
        "enough to explain to",
        "a  computer.  Art is",
        "everything  else  we",
        "do                  "
    };
    
    int maxWidth = 20;
    EXPECT_EQ(fullJustify(words, maxWidth), ans);
    EXPECT_EQ(fullJustify1(words, maxWidth), ans);
}

TEST(case_3, content)
{
    std::vector<std::string> words = {"What","must","be","acknowledgment","shall","be"};
    std::vector<std::string> ans = {
        "What   must   be",
        "acknowledgment  ",
        "shall be        "
    };

    int maxWidth = 16; 
    EXPECT_EQ(fullJustify(words, maxWidth), ans);
    EXPECT_EQ(fullJustify1(words, maxWidth), ans);
}