#include "347.TopKFrequentElements.h"
#include <algorithm>
#include <functional>
#include <map>

std::vector<int> topKFrequent(std::vector<int>& nums, int k) 
{
    std::vector<int> vecRes;
    if(nums.size() == 0) {
        return vecRes;
    }

    std::map<int, int> mapCount;
    for(const auto & iNum : nums) {
        ++mapCount[iNum];
    }

    // printf("%d\n", mapCount.size());

    std::multimap<int, int, std::greater<int> > mapTopK;
    auto pIter = mapCount.begin();
    while(pIter != mapCount.end()) 
    {
        mapTopK.insert(std::pair<int, int>(pIter->second, pIter->first));
        ++pIter;
    }

    // printf("%d\n", mapTopK.size());

    auto pResIter = mapTopK.begin();
    for(int i = 0; i < k && pResIter != mapTopK.end(); ++i, ++pResIter) {   
        vecRes.push_back(pResIter->second);
    }

    return vecRes;
}