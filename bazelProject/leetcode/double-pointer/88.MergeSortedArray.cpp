#include "88.MergeSortedArray.h"
#include <algorithm>


void merge1(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
    int iIdx = nums1.size() - 1;
    while(m > 0 && n > 0)
    {
        if(nums1[m-1] > nums2[n-1]) 
        {
            nums1[iIdx] = nums1[m-1];
            --m;
        }else 
        {
            nums1[iIdx] = nums2[n-1];
            --n;
        }
        --iIdx;
    }

    while(m>0)
    {
        nums1[iIdx] = nums1[m-1];
        --iIdx;
        --m;
    }

    while(n>0)
    {
        nums1[iIdx] = nums2[n-1];
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


void merge2(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int iIdx = nums1.size() - 1;
    while(m && n) {
        if(nums2[n - 1] > nums1[m - 1]) {
            nums1[iIdx--] = nums2[--n];
        }else {
            nums1[iIdx--] = nums1[--m];
        }
    }

    while(n) {
        nums1[iIdx--] = nums2[--n];
    }
}


// 一种是重新申请一片空间，一种是倒着来，节省空间
void merge3(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int iIdx = m + n - 1;
    while(m && n) {
        if(nums2[n - 1] > nums1[m - 1]) {
            nums1[iIdx--] = nums2[--n];
        }else {
            nums1[iIdx--] = nums1[--m];
        }
    }    
    while(n) {
        nums1[iIdx--] = nums2[--n];
    }

}