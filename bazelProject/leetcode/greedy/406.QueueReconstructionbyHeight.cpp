#include "406.QueueReconstructionbyHeight.h"
#include <algorithm>
#include <iostream>

// 排序后，直接插入排序
std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people)
{
    std::sort(people.begin(), people.end(), [](std::vector<int> & a, std::vector<int> & b){
        if(a[0] != b[0]) {
            return a[0] > b[0];
        }
        return a[1] < b[1];
    });

    std::vector<std::vector<int>> vecRes;
    for(int i = 0; i < people.size(); ++i)
    {
        if(people[i][1] == 0) {
            vecRes.insert(vecRes.begin(), people[i]);
        }else
        {
            int iHigherNum = people[i][1];
            int iIdx = 0;
            for(; iIdx < vecRes.size() && iHigherNum; ++iIdx)
            {
                if(vecRes[iIdx][0] >= people[i][0]) {
                    --iHigherNum;
                }
            }

            if(iIdx < vecRes.size()) {
                vecRes.insert(vecRes.begin() + iIdx, people[i]);
            }else{
                vecRes.push_back(people[i]);
            }
        }
    }

    return vecRes;
}

// 找对应的位置
std::vector<std::vector<int>> reconstructQueue1(std::vector<std::vector<int>>& people)
{
    std::sort(people.begin(), people.end(), [](std::vector<int> & a, std::vector<int> & b) {
        if(a[0] != b[0]) {
            return a[0] < b[0];
        }else{
            return a[1] < b[1];
        }
    }); 

    std::vector<std::vector<int>> vecRes(people.size());
    std::vector<int> vecFlag(people.size(), 0);
    for(int i = 0; i < people.size(); ++i)
    {
        int iCnt = people[i][1];
        int iIdx = 0;
        for(; iIdx < vecRes.size(); ++iIdx)
        {
            if(vecFlag[iIdx] == 1 && vecRes[iIdx][0] < people[i][0]) {
                continue;
            }else 
            {
                if(iCnt == 0) {
                    break;
                }
                if(vecFlag[iIdx] == 0 || vecRes[iIdx][0] >= people[i][0]){
                    --iCnt;
                }
            }

        }

        if(iIdx <= vecRes.size() - 1) 
        {
            vecRes[iIdx] = people[i];
            vecFlag[iIdx] = 1;
        }else{
            vecRes[vecRes.size() - 1] = people[i];
            vecFlag[vecRes.size() - 1] = 1;
        }
        
    }

    return vecRes;
}