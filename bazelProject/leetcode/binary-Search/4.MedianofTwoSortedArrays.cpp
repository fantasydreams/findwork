#include "4.MedianofTwoSortedArrays.h"
#include <cmath>
#include <climits>

// 归并排序思路
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    size_t total = nums1.size() + nums2.size();
    size_t mid = total >> 1, pos = 0;
    size_t idx1 = 0, idx2 = 0;
    int64_t pre, cur;
    
    while(pos <= mid && idx1 < nums1.size() && idx2 < nums2.size()) 
    {
        pre = cur;
        if(nums1[idx1] < nums2[idx2]) {
            cur = nums1[idx1++];
        }else {
            cur = nums2[idx2++];
        }
        ++pos;
    }

    while(pos <= mid && idx1 < nums1.size())
    {
        pre = cur;
        cur = nums1[idx1++];
        ++pos;
    }

    while(pos <= mid && idx2 < nums2.size())
    {
        pre = cur;
        cur = nums2[idx2++];
        ++pos;
    }

    if(total & 0x1){
        return cur;
    }else {
        return ((double)pre + cur) / 2;
    }
}

//二分查找思路
// reference :https://blog.csdn.net/qq_25424545/article/details/84567300
// 以查找k个元素，那么k/2，两个数组加起来一定不超过k个元素，有一段一定可以排除，然后递归
int findKth(vector<int>& nums1,  vector<int>& nums2, int idxa, int idxb, int kth)
{
    if(idxa >= nums1.size()) return nums2[idxb + kth - 1];
    if(idxb >= nums2.size()) return nums1[idxa + kth - 1];
    if(kth == 1) return min(nums1[idxa], nums2[idxb]);

    int step = (kth >> 1) - 1;
    int vala = (idxa + step) >= nums1.size() ? INT_MAX : nums1[idxa + step];
    int valb = (idxb + step) >= nums2.size() ? INT_MAX : nums2[idxb + step];
    if(vala > valb) {
        return findKth(nums1, nums2, idxa, idxb + step + 1, kth - (kth >> 1));
    }else {
        return findKth(nums1, nums2, idxa + step + 1, idxb, kth - (kth >> 1));
    }
}

double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2)
{
    int total = nums1.size() + nums2.size();
    if(total & 0x1) {
        return findKth(nums1, nums2, 0, 0, (total >> 1) + 1);
    }else {
        return ((double)findKth(nums1, nums2, 0, 0, (total >> 1) + 1) + findKth(nums1, nums2, 0, 0, (total >> 1))) / 2;
    }
}



double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2, int n1s, int n2s, int idx) {
    if(n1s >= nums1.size()) {
        return nums2[n2s + idx - 1];
    }
    if(n2s >= nums2.size()) {
        return nums1[n1s + idx - 1];
    }
    if(idx == 1) { //因为索引从1开始，所以为1的时候要直接返回当前的最小值
        return std::min(nums1[n1s], nums2[n2s]);
    }

    int step = (idx >> 1) - 1; //>> 运算符比算数运算符的优先级要低
    int num1 = n1s + step >= nums1.size() ? INT_MAX : nums1[n1s + step];
    int num2 = n2s + step >= nums2.size() ? INT_MAX : nums2[n2s + step];
    if(num1 < num2) { //过滤掉一半
        return findMedianSortedArrays2(nums1, nums2, n1s + step + 1, n2s, idx - (idx >> 1));
    }else {
        return findMedianSortedArrays2(nums1, nums2, n1s, n2s + step + 1, idx - (idx >> 1));
    }

}


double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
    int total = nums1.size() + nums2.size();
    if(total == 0) {
        return -1;//找不到
    }

    if(total & 0x1) {
        return findMedianSortedArrays2(nums1, nums2, 0, 0, (total >> 1) + 1); //注意右移运算符比算数运算符优先级低
    }else {
        return ((double)findMedianSortedArrays2(nums1, nums2, 0, 0, (total >> 1) + 1) + 
                (double)findMedianSortedArrays2(nums1, nums2, 0, 0, (total >> 1))) / 2;
    }
}






















// int findMergenumber(vector<int>& nums1, vector<int>& nums2,int idx_A,int idx_B, int idx){
//         if(idx_A >= nums1.size()) return nums2[idx_B + idx - 1];
//         if(idx_B >= nums2.size()) return nums1[idx_A + idx - 1];
//         if(idx == 1) return min(nums1[idx_A],nums2[idx_B]);
        
//         int k = idx / 2 - 1;
//         int A = (idx_A + k>= nums1.size()) ? INT_MAX:nums1[idx_A + k];
//         int B = (idx_B + k>= nums2.size()) ? INT_MAX:nums2[idx_B + k];
//         if(A > B) return findMergenumber(nums1,nums2,idx_A,idx_B + idx/2,idx-idx/2);
//         else return findMergenumber(nums1,nums2,idx_A + idx/2,idx_B,idx-idx/2);
//     }
    
// double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
//     int sum = nums1.size() + nums2.size();
//     if(sum % 2 == 0){
//         return ((double)findMergenumber(nums1,nums2,0,0,(sum)/2) + findMergenumber(nums1,nums2,0,0,sum/2 + 1)) / 2;
//     }else{
//         return findMergenumber(nums1,nums2,0,0,sum/2 + 1);
//     }
// }