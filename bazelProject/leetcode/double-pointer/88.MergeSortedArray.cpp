#include "88.MergeSortedArray.h"
#include <algorithm>


void merge1(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
    int iIdx = nums1.size() - 1;
    while(m >= 0 && n >= 0)
    {
        if(nums1[m] > nums2[n]) 
        {
            nums1[iIdx] = nums1[m];
            --m;
        }else 
        {
            nums1[iIdx] = nums2[n];
            --n;
        }
        --iIdx;
    }

    while(m>=0)
    {
        nums1[iIdx] = nums1[m];
        --iIdx;
        --m;
    }

    while(n>=0)
    {
        nums1[iIdx] = nums2[n];
        --iIdx;
        --n;
    }
}

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
    std::vector<int> vecRes(nums1.size());
    int iIdx = 0, i = 0, j = 0;
    while(i < m && j < n)
    {
        if(nums1[i] < nums2[j]) {
            vecRes[iIdx++] = nums1[i++];
        }else {
            vecRes[iIdx++] = nums2[j++];
        }
    }

    while(i < m) {
        vecRes[iIdx++] = nums1[i++];
    }
    while(j < n) {
        vecRes[iIdx++] = nums2[j++];
    }

    std::swap(nums1, vecRes);
}