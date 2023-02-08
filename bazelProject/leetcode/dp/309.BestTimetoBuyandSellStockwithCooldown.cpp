#include "309.BestTimetoBuyandSellStockwithCooldown.h"
#include <climits>

// blog https://blog.csdn.net/zjuPeco/article/details/76468185

// s0 —— sell后rest或者rest后rest
// s1 —— rest后的buy或者buy后的rest
// s2 —— rest后的sell


int maxProfit(vector<int>& prices)
{
    if(prices.size() <= 1) {
        return 0;
    }
    std::vector<int> s0(prices.size() + 1, 0), s1(prices.size() + 1, -prices[0]), s2(prices.size() + 1, INT_MIN);
    for(int i = 1; i <= prices.size(); ++i)
    {
        s0[i] = std::max(s0[i - 1], s2[i - 1]);
        s1[i] = std::max(s1[i - 1], s0[i - 1] - prices[i]);
        s2[i] = s1[i - 1] + prices[i];
    }

    return std::max(s2[prices.size()], s0[prices.size()]);
}


int maxProfit1(vector<int>& prices) 
{
    if (prices.size() <= 1)
        return 0;
    int s0 = 0;
    int s1 = -prices[0];
    int s2 = INT_MIN;
    for (int i = 1; i < prices.size(); i++)
    {
        int pre0 = s0;
        int pre1 = s1;
        s0 = max(s0, s2);
        s1 = max(pre0 - prices[i], s1);
        s2 = pre1 + prices[i];
    }
    //最大利润不可能出现在buy而未sell的时候，所以不考虑s1
    return max(s0, s2);
}
