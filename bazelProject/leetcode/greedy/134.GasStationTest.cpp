#include "134.GasStation.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    std::vector<int> gas = {1,2,3,4,5};
    std::vector<int> cost = {3,4,5,1,2};
    int ans = 3;
    EXPECT_EQ(canCompleteCircuit(gas, cost), ans);
    EXPECT_EQ(canCompleteCircuit1(gas, cost), ans);
    EXPECT_EQ(canCompleteCircuit2(gas, cost), ans); 
}


TEST(case_2, content) {
    std::vector<int> gas = {2,3,4};
    std::vector<int> cost = {3,4,3};
    int ans = -1;
    EXPECT_EQ(canCompleteCircuit(gas, cost), ans);
    EXPECT_EQ(canCompleteCircuit1(gas, cost), ans);
    EXPECT_EQ(canCompleteCircuit2(gas, cost), ans); 
}

TEST(case_3, content) {
    std::vector<int> gas = {5,8,2,8};
    std::vector<int> cost = {6,5,6,6};
    int ans = 3;
    EXPECT_EQ(canCompleteCircuit(gas, cost), ans);
    EXPECT_EQ(canCompleteCircuit1(gas, cost), ans);
    EXPECT_EQ(canCompleteCircuit2(gas, cost), ans); 
}

TEST(case_4, content) {
    std::vector<int> gas = {5,1,2,3,4};
    std::vector<int> cost = {4,4,1,5,1};
    int ans = 4;
    EXPECT_EQ(canCompleteCircuit(gas, cost), ans);
    EXPECT_EQ(canCompleteCircuit1(gas, cost), ans);
    EXPECT_EQ(canCompleteCircuit2(gas, cost), ans); 
}


TEST(case_5, content) {
    std::vector<int> gas = {1,1,2,3};
    std::vector<int> cost = {2,3,1,1};
    int ans = 2;
    EXPECT_EQ(canCompleteCircuit(gas, cost), ans);
    EXPECT_EQ(canCompleteCircuit1(gas, cost), ans);
    EXPECT_EQ(canCompleteCircuit2(gas, cost), ans); 
}