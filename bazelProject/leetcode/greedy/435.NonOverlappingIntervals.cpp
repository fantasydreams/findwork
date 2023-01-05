#include "435.NonOverlappingIntervals.h"
#include <algorithm>

int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals)
{
    if(intervals.size() <= 1) {
        return 0;
    }

    std::sort(intervals.begin(), intervals.end(), [](std::vector<int> & a, std::vector<int> & b){return a[1] < b[1];});

    int iIdx = 0;
    uint32_t iDorpCnt = 0;
    for(int i = 1; i < intervals.size(); ++ i)
    {
        if(intervals[iIdx][1] > intervals[i][0]) {
            ++iDorpCnt;
        }else  {
            iIdx = i;
        }
    }

    return iDorpCnt;
}