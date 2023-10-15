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

    for(int iIdx = ratings.size() - 2; iIdx >= 0 ; --iIdx)
    {
        if(ratings[iIdx] > ratings[iIdx + 1]){
            vecCandy[iIdx] = std::max(vecCandy[iIdx + 1] + 1, vecCandy[iIdx]) ;
        }
    }
    return std::accumulate(vecCandy.begin(), vecCandy.end(), 0);
}

int candy1(std::vector<int> &ratings) {
    if(ratings.size() < 2) {
        return ratings.size();
    }

    std::vector<uint32_t> vecCandy(ratings.size(), 1);
    for(int i = 1; i < ratings.size(); ++i) {
        if(ratings[i] > ratings[i - 1]) {
            vecCandy[i] = vecCandy[i - 1] + 1;
        }
    }

    for(int i = ratings.size() - 2; i >= 0; --i) {
        if(ratings[i] > ratings[i + 1]) {
            vecCandy[i] = std::max(vecCandy[i], vecCandy[i + 1] + 1);
        }
    }

    return std::accumulate(vecCandy.begin(), vecCandy.end(), 0);
}