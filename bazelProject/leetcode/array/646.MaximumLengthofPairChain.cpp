#include "646.MaximumLengthofPairChain.h"
#include <algorithm>

int findLongestChain(vector<vector<int>>& pairs)
{
    if(pairs.size() == 0) {
        return 0;
    }

    //pair的数组类型，固有思路是按照第一个元素进行排序，其实大多数题型都是按照第二个元素去排序，更好想思路和进行解题
    std::sort(pairs.begin(), pairs.end(), [&](vector<int> & a, vector<int> & b){
        if(a[1] != b[1]) {
            return a[1] < b[1];
        }else {
            return a[0] > b[0]; //大的在前面保证区间更短
        }
    });

    int ans = 1, idx = 0;
    for(int i = 1; i < pairs.size(); ++i)
    {
        if(pairs[i][1] == pairs[i - 1][1]) {
            continue;
        }

        if(pairs[i][0] > pairs[idx][1]) 
        {
            ++ans;
            idx = i;
        }
    }

    return ans;
}

int findLongestChainDp(vector<vector<int>>& pairs)
{
    if(pairs.size() == 0) {
        return 0;
    }

    std::vector<int> dp(pairs.size(), 1);
    std::sort(pairs.begin(), pairs.end(), [&](vector<int> & a, vector<int> & b){
        if(a[0] != b[0]) {
            return a[0] < b[0];
        }else {
            return a[1] < b[1];
        }
    });

    for(int i = 0; i < pairs.size(); ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            dp[i] = max(dp[i], pairs[j][1] < pairs[i][0] ? dp[j] + 1 : dp[j]);
        }
    }

    return dp[pairs.size() -1];
}