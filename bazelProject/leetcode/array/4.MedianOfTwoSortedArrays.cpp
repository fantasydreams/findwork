#include "4.MedianOfTwoSortedArrays.h"

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