#include "4.MedianOfTwoSortedArrays.h"
#include <climits>

// 第一种方式，采用归并排序，先将已经排好序的两个数组进行归并排序
// 空间复杂度O(N)，时间复杂度O(N)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    vector<int> tmp(nums1.size() + nums2.size());
    size_t i = 0, j = 0 , idx = 0;    
    while(i < nums1.size() && j < nums2.size())
    {
        if(nums1[i] < nums2[j]){
            tmp[idx++] = nums1[i++];
        }else{
            tmp[idx++] = nums2[j++];
        }
    }
    while(i < nums1.size()) {
        tmp[idx++] = nums1[i++];
    }
    while(j < nums2.size()) {
        tmp[idx++] = nums2[j++];
    }

    if(tmp.size() % 2 == 0){
        return (double)tmp[(tmp.size())/2 - 1] / 2 + (double)tmp[tmp.size() / 2] / 2;
    }else {
        return (double)tmp[tmp.size() / 2];
    }

    return 0;
}

// 第二种，采用归并排序的思路，但是不将两个数组进行合并
// 空间复杂度O(1)，时间复杂度O(N)

double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) 
{
    size_t i = 0, j = 0, idx = (nums2.size() + nums1.size()) / 2;
    int tmp = 0;
    while(i+j < idx && i < nums1.size() && j < nums2.size())
    {
        if(nums1[i] < nums2[j])
        {
            tmp = nums1[i++];
            
        }else{
            tmp = nums2[j++];
        }
    }
    while(i+j < idx && i < nums1.size()){
        tmp = nums1[i++];
    }
    while(i+j < idx && j < nums2.size()){
        tmp = nums2[j++];
    }

    int another = 0;
    if(i < nums1.size() && j < nums2.size()){
        another = min(nums1[i],nums2[j]);
    }else if(i < nums1.size()){
        another = nums1[i];
    }else{
        another = nums2[j];
    }
    if((nums1.size() + nums2.size()) % 2 != 0){
        return another;
    }else {
        return ((double)tmp + another)/2;
    }
    return 0;
}

// 第三种，采用二分查找的思路，
// 空间复杂度O(1)，时间复杂度O(logn)
// 中位数有个特点，对于奇数个数字，一定是一半元素之后的那一个数字，因此排除前一半的元素就可以了
// 

double findKth(const vector<int>& nums1, const vector<int>& nums2, size_t aIdx, size_t bIdx, size_t k)
{
    if(nums1.size() <= aIdx) return nums2[bIdx + k - 1];
    if(nums2.size() <= bIdx) return nums1[aIdx + k - 1];
    if(k == 1) return min(nums1[aIdx], nums2[bIdx]);

    size_t inewK = k / 2 - 1;
    int aValue = nums1.size() > aIdx + inewK ? nums1[aIdx + inewK] : INT_MAX;
    int bValue = nums2.size() > bIdx + inewK ? nums2[bIdx + inewK] : INT_MAX;
    
    if(aValue < bValue){
        return findKth(nums1, nums2, aIdx + k/2, bIdx, k - k/2);
    }else{
        return findKth(nums1, nums2, aIdx, bIdx + k/2, k - k/2);
    }
}

double findMedianSortedArraysBinarySearch(const vector<int>& nums1, const vector<int>& nums2) 
{
    size_t iLen = nums1.size() + nums2.size();
    bool bOdd = (iLen) % 2;
    size_t iHalf = (iLen) / 2;
    if(bOdd)
    {
        double iSum = findKth(nums1, nums2, 0, 0, iHalf + 1);
        return iSum;
    }else
    {
        double iSum = findKth(nums1, nums2, 0, 0, iHalf) + findKth(nums1, nums2, 0, 0, iHalf + 1);
        return iSum / 2;
    }
    return 0;
}


double findKthNotRecursion(const vector<int>& nums1, const vector<int>& nums2, size_t k)
{
    size_t aIdx = 0, bIdx = 0, kTh = k;
    while(aIdx < nums1.size() && bIdx < nums2.size() && kTh > 1)
    {
        int _k = kTh / 2 -1;
        int aValue = nums1.size() > (aIdx + _k) ? nums1[aIdx + _k] : INT_MAX;
        int bValue = nums2.size() > (bIdx + _k) ? nums2[bIdx + _k] : INT_MAX;
        if(aValue < bValue){
            aIdx += kTh / 2;
        }else{
            bIdx += kTh / 2;
        }
        kTh -= kTh / 2;
    }

    if(nums1.size() <= aIdx){
        return nums2[bIdx + kTh - 1];
    }
    if(nums2.size() <= bIdx){
        return nums1[aIdx + kTh - 1];
    }
    if(kTh == 1) return min(nums1[aIdx], nums2[bIdx]);
}


double findMedianSortedArraysBinarySearchNotRecursion(const vector<int>& nums1, const vector<int>& nums2) 
{
    size_t iLen = nums1.size() + nums2.size();
    bool bOdd = (iLen) % 2;
    size_t iHalf = (iLen) / 2;
    if(bOdd)
    {
        double iSum = findKthNotRecursion(nums1, nums2, iHalf + 1);
        printf("%f / 1\n", iSum);
        return iSum;
    }else
    {
        double iSum = findKthNotRecursion(nums1, nums2, iHalf) + findKthNotRecursion(nums1, nums2, iHalf + 1);
        printf("%f / 2\n", iSum);
        return iSum / 2;
    }
    return 0;
}

double findKthNotRecursion1(const vector<int>& nums1, const vector<int>& nums2, size_t k) {
    int aIdx = 0, bIdx = 0;
    while(aIdx < nums1.size() && bIdx < nums2.size() && k > 1) {
        int newK = k / 2 - 1;
        int a = nums1.size() > aIdx + newK ? nums1[aIdx + newK] : INT_MAX;
        int b = nums2.size() > bIdx + newK ? nums2[bIdx + newK] : INT_MAX;
        if(a < b) {
            aIdx += k / 2;
        }else {
            bIdx += k / 2;
        }
        k -= k / 2;
    }

    if(aIdx >= nums1.size()) {
        return nums2[bIdx + k - 1];
    }
    if(bIdx >= nums2.size()) {
        return nums1[aIdx + k - 1];
    }

    if(k == 1) return std::min(nums1[aIdx], nums2[bIdx]);
}

double findMedianSortedArraysBinarySearchNotRecursion1(const vector<int>& nums1, const vector<int>& nums2) {
    int iTotal = nums1.size() + nums2.size();
    int iHalf = iTotal / 2;
    if(iTotal % 2 == false) {
        double a = findKthNotRecursion1(nums1, nums2, iHalf);
        double b = findKthNotRecursion1(nums1, nums2, iHalf + 1);
        return (a + b) / 2;
    }else {
        return findKthNotRecursion1(nums1, nums2, iHalf + 1);
    }
    return 0;
}

double findKth1(const vector<int>& nums1, const vector<int>& nums2, size_t aIdx, size_t bIdx, size_t k) {
    if(aIdx >= nums1.size()) return nums2[bIdx + k - 1];
    if(bIdx >= nums2.size()) return nums1[aIdx + k - 1];
    if(k == 1) {
        return std::min(nums1[aIdx], nums2[bIdx]);
    }

    int iNewK =  k / 2 - 1;
    int a = aIdx + iNewK >= nums1.size() ? INT_MAX : nums1[aIdx + iNewK];
    int b = bIdx + iNewK >= nums2.size() ? INT_MAX : nums2[bIdx + iNewK];
    if(a < b) {
        return findKth1(nums1, nums2, aIdx + k / 2, bIdx, k - k / 2);
    }else {
        return findKth1(nums1, nums2, aIdx, bIdx + k / 2, k - k / 2);
    }
}

double findMedianSortedArraysBinarySearch1(const vector<int>& nums1, const vector<int>& nums2) {
    int iTotal = nums1.size() + nums2.size();
    int iHalf = iTotal / 2;
    if(iTotal % 2 == false) {
        double a = findKth1(nums1, nums2, 0, 0, iHalf);
        double b = findKth1(nums1, nums2, 0, 0, iHalf + 1);
        return (a + b) / 2;
    }else {
        return findKth1(nums1, nums2, 0, 0, iHalf + 1);
    }
    return 0;
}