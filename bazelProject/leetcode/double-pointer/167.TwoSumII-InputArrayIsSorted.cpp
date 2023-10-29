#include "167.TwoSumII-InputArrayIsSorted.h"

std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    std::vector<int> vecRes;
    int iStart = 0, iEnd = numbers.size() - 1;
    while(iStart < iEnd)
    {
        int iSum = numbers[iStart] + numbers[iEnd];
        if(iSum < target) 
        {
            ++iStart;
        }else if(iSum > target) 
        {
            --iEnd;
        }else 
        {
            vecRes.push_back(iStart+1);
            vecRes.push_back(iEnd+1);
            break;
        }
    }

    return vecRes;
}



std::vector<int> twoSum1(std::vector<int>& numbers, int target) {
    int iStart = 0, iEnd = numbers.size() - 1;
    while(iStart < iEnd) {
        int sum = numbers[iStart] + numbers[iEnd];
        if(sum == target) {
            return {iStart + 1, iEnd + 1};
        }else if(sum < target) {
            ++iStart;
        }else {
            --iEnd;
        }
    }

    return {};
}