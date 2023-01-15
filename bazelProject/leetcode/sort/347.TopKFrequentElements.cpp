#include "347.TopKFrequentElements.h"
#include <unordered_map>
#include <cmath>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k)
{
    unordered_map<int, int> mapCnt;
    int iBucketSize = 0;
    for(const auto & iNum : nums) {
        iBucketSize = max(++mapCnt[iNum], iBucketSize);
    }

    vector<vector<int>> vecBucket(iBucketSize);
    for(const auto & oPair : mapCnt) {
        vecBucket[oPair.second - 1].push_back(oPair.first);
    }

    vector<int> vecAns;
    for(int i = iBucketSize - 1; i >= 0 && vecAns.size() < k; --i)
    {
        for(const auto & num : vecBucket[i]) 
        {
            vecAns.push_back(num);
            if(vecAns.size() == k) {
                break;
            }
        }
    }

    return vecAns;
}