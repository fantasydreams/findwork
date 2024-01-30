#include "88.MergeSortedArray.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
	std::vector<int> num1 = {1,2,3,0,0,0};
    std::vector<int> num2 = {2,5,6};
    std::vector<int> vecRes = {1,2,2,3,5,6};
    merge(num1,num1.size() - num2.size(), num2,num2.size());
    EXPECT_EQ(num1, vecRes);

    num1 = {1,2,3,0,0,0};
    num2 = {2,5,6};
    merge1(num1,num1.size() - num2.size(), num2,num2.size());
    EXPECT_EQ(num1, vecRes);


    num1 = {1,2,3,0,0,0};
    num2 = {2,5,6};
    merge2(num1,num1.size() - num2.size(), num2,num2.size());
    EXPECT_EQ(num1, vecRes);

    num1 = {1,2,3,0,0,0};
    num2 = {2,5,6};
    merge3(num1,num1.size() - num2.size(), num2,num2.size());
    EXPECT_EQ(num1, vecRes); 
}


TEST(case_2,content)
{
	std::vector<int> num1 = {1,2, 0,0};
    std::vector<int> num2 = {1,2};
    std::vector<int> vecRes = {1,1,2,2};
    merge(num1,num1.size() - num2.size(), num2,num2.size());
    EXPECT_EQ(num1, vecRes);

    num1 = {1,2, 0,0};
    num2 = {1,2};
    merge1(num1,num1.size() - num2.size(), num2,num2.size());
    EXPECT_EQ(num1, vecRes);

    num1 = {1,2, 0,0};
    num2 = {1,2};
    merge2(num1,num1.size() - num2.size(), num2,num2.size());
    EXPECT_EQ(num1, vecRes);
    
    num1 = {1,2, 0,0};
    num2 = {1,2};
    merge3(num1,num1.size() - num2.size(), num2,num2.size());
    EXPECT_EQ(num1, vecRes);
}

TEST(case_3,content)
{
	std::vector<int> num1 = {0};
    std::vector<int> num2 = {1};
    std::vector<int> vecRes = {1};
    merge(num1,num1.size() - num2.size(), num2,num2.size());
    EXPECT_EQ(num1, vecRes);

    num1 = {0};
    num2 = {1};
    merge1(num1,num1.size() - num2.size(), num2,num2.size());
    EXPECT_EQ(num1, vecRes);

    num1 = {0};
    num2 = {1};
    merge2(num1,num1.size() - num2.size(), num2,num2.size());
    EXPECT_EQ(num1, vecRes);

    num1 = {0};
    num2 = {1};
    merge3(num1,num1.size() - num2.size(), num2,num2.size());
    EXPECT_EQ(num1, vecRes);
}

TEST(case_4,content)
{
	std::vector<int> num1 = {1};
    std::vector<int> num2 = {};
    std::vector<int> vecRes = {1};
    merge(num1,num1.size() - num2.size(), num2,num2.size());
    EXPECT_EQ(num1, vecRes);

    num1 = {1};
    num2 = {};
    merge1(num1,num1.size() - num2.size(), num2,num2.size());
    EXPECT_EQ(num1, vecRes);

    num1 = {1};
    num2 = {};
    merge2(num1,num1.size() - num2.size(), num2,num2.size());
    EXPECT_EQ(num1, vecRes);

    num1 = {1};
    num2 = {};
    merge3(num1,num1.size() - num2.size(), num2,num2.size());
    EXPECT_EQ(num1, vecRes);
}