#include "763.PartitionLabels.h"

std::vector<int> partitionLabels(std::string s)
{
    if(s.size() <= 0) {
        return {};
    }
    if(s.size() == 1) {
        return {1};
    }

    std::vector<int> vecLastPos(128, 0);
    for(size_t iIdx = 0; iIdx < s.size(); ++iIdx) {
        vecLastPos[s[iIdx]] = iIdx;
    }

    std::vector<int> vecRes;
    int iCurLast = vecLastPos[s[0]];
    int iOldPos = 0;
    for(int iIdx = 0; iIdx < s.size(); ++iIdx)
    {
        if(iIdx == iCurLast || iIdx == s.size() - 1) 
        {
            vecRes.push_back(iIdx - iOldPos + 1);
            iOldPos = iIdx + 1;
            if(iIdx < s.size() - 1) {
                iCurLast = vecLastPos[s[iIdx + 1]];
            }
        }else
        {
            if(vecLastPos[s[iIdx]] > iCurLast) {
                iCurLast = vecLastPos[s[iIdx]];
            }
        }
    }

    return vecRes;
}