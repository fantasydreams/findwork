#include "225.ImplementStackusingQueues.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    MyStack st;
    st.push(1);
    st.push(2);
    
    EXPECT_EQ(st.top(), 2);
    st.pop();
    EXPECT_EQ(st.empty(), false);
    EXPECT_EQ(st.top(), 1);
    st.pop();
    EXPECT_EQ(st.empty(), true);
}


TEST(case_2,content)
{
    MyStack1 st;
    st.push(1);
    st.push(2);
    
    EXPECT_EQ(st.top(), 2);
    st.pop();
    EXPECT_EQ(st.empty(), false);
    EXPECT_EQ(st.top(), 1);
    st.pop();
    EXPECT_EQ(st.empty(), true);
}