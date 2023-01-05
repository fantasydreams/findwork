#include "135.Candy.h"
#include <algorithm>
#include <numeric>

int candy(std::vector<int>& ratings)
{
    if(ratings.size() < 2) {
        return ratings.size();
    }

    std::vector<uint32_t> vecCandy(ratings.size(), 1);
    for(int iIdx = 1; iIdx < ratings.size(); ++iIdx)
    {
        if(ratings[iIdx - 1] < ratings[iIdx]) {
            vecCandy[iIdx] = vecCandy[iIdx-1] + 1;
        }
    }

    for(int iIdx = ratings.size() - 2; iIdx >= 0 ; ++iIdx)
    {
        if(ratings[iIdx] > ratings[iIdx + 1]){
            vecCandy[iIdx] = vecCandy[iIdx + 1] + 1;
        }
    }
    return std::accumulate(vecCandy.begin(), vecCandy.end(), 0);
}