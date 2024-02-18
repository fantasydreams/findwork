#include "452.MinimumNumberofArrowstoBurstBalloons.h"
#include <algorithm>

int findMinArrowShots(std::vector<std::vector<int>>& points)
{
    if(points.size() <= 1) {
        return points.size();
    }

    std::sort(points.begin(), points.end(), [](std::vector<int> & a, std::vector<int> & b) {
        if(a[0] != b[0]) {
            return a[0] < b[0];
        }else{
            return a[1] < b[1];
        }
    });
    int iXEnd = points[0][1];
    int iRes = 1;
    for(int iIdx = 1; iIdx < points.size(); ++iIdx)
    {
        if(points[iIdx][0] > iXEnd)
        {
            ++iRes;
            iXEnd = points[iIdx][1];
        }else{
            iXEnd = std::min(iXEnd, points[iIdx][1]);
        }
    }

    return iRes;
}

int findMinArrowShots2(std::vector<std::vector<int>>& points)
{
    if(points.size() <= 1) {
        return points.size();
    }

    std::sort(points.begin(), points.end(), [](std::vector<int> & a, std::vector<int> & b) {
        if(a[1] != b[1]){
            return a[1] < b[1];
        }else {
            return a[0] < b[0];
        }
    });
    int iXEnd = points[0][1];
    int iRes = 1;
    for(int iIdx = 1; iIdx < points.size(); ++iIdx)
    {
        if(points[iIdx][0] > iXEnd)
        {
            ++iRes;
            iXEnd = points[iIdx][1];
        }
    }

    return iRes;
}


int findMinArrowShots3(std::vector<std::vector<int>>& points) {
    if(points.size() <= 1) {
        return points.size();
    }

    std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        if(a[1] != b[1]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    });

    int ans = 1;
    int iMax = points[0][1];
    for(int i = 1; i < points.size(); ++i) {
        if(points[i][0] > iMax) {
            ++ans;
            iMax = points[i][1];
        }
    }

    return ans;
}


int findMinArrowShots4(std::vector<std::vector<int> >& points) { 
    if(points.size() <= 1) {
        return points.size();
    }

    std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b){
        if(a[0] != b[0]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    });

    int ans = 1, iMax = points[0][1];
    for(int i = 1; i < points.size(); ++i) {
        if(points[i][0] <= iMax) {
            iMax = std::min(iMax, points[i][1]);
        }else {
            ++ans;
            iMax = points[i][1];
        }
    }

    return ans;
}