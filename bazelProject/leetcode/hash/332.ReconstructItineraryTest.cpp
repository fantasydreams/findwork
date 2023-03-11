#include "332.ReconstructItinerary.h"
#include "gtest/gtest.h"

// Input: nums = {1,1,1,2,2,3}, k = 2
// Output: {1,2}

TEST(case_1,content)
{
    std::vector<vector<string>> tickets = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
    std::vector<string> Output = {"JFK","MUC","LHR","SFO","SJC"};
    EXPECT_EQ(findItinerary(tickets), Output);   
}

TEST(case_2,content)
{
    std::vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    std::vector<string> Output = {"JFK","ATL","JFK","SFO","ATL","SFO"};
    EXPECT_EQ(findItinerary(tickets), Output);   
}

TEST(case_3,content)
{
    std::vector<vector<string>> tickets = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}, {"JFK", "OFC"}, {"OFC", "JFK"}};
    std::vector<string> Output = {"JFK","OFC","JFK","MUC","LHR","SFO","SJC"};
    EXPECT_EQ(findItinerary(tickets), Output);   
}