//
// Created by Sharwen on 2020/1/7.
//
#include "../../header/offer/4.h"
#include <algorithm>

//time: O(m+n);
//space:O(m+n);
//简单的归并
/*double Solution4::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    vector<int> merge(nums1.size() + nums2.size());

    int i=0,j=0,idx = 0;
    while(i<nums1.size() && j < nums2.size()){
        if(nums1[i] < nums2[j]) {
            merge[idx++] = nums1[i++];
        }
        else{
            merge[idx++] = nums2[j++];
        }
    }

    while(i<nums1.size()){
        merge[idx++] = nums1[i++];
    }
    while(j<nums2.size()){
        merge[idx++] = nums2[j++];
    }

    if(merge.size() % 2){
        return merge[merge.size()/2];
    } else{
        return ((double)merge[merge.size()/2] + merge[merge.size()/2 - 1]) / 2;
    }
}*/

/*
double Solution4::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2){
    int size = nums1.size() + nums2.size();
    int medium_idx = size/2;
    bool even = false;
    int first=0,second = 0;
    if(size % 2 == 0) {
        even = true;
    }

    int i=0,j=0,idx = 0;
    while(i<nums1.size() && j < nums2.size() && idx <= medium_idx){
        first = second;
        if(nums1[i] < nums2[j]){
            second = nums1[i++];
        } else{
            second = nums2[j++];
        }
        ++idx;
    }

    while(i < nums1.size() && idx <= medium_idx){
        first = second;
        second = nums1[i++];
        idx++;
    }

    while(j < nums2.size() && idx <= medium_idx){
        idx++;
        first = second;
        second = nums2[j++];
    }

    if(even){
        return (first + second) / 2.0;
    }else{
        return second;
    }
}
 */


int findKthNumber(const vector<int> & A,const vector<int> & B,int Aidx,int Bidx,int Kth){


    if(A.size() <= Aidx){ //这里的条件可以是等于，因为不可能舍弃的元素超过本数组中的个数
        return B[Bidx + Kth - 1];
    }else if(B.size() <= Bidx){
        return A[Aidx + Kth - 1];
    }

    if(Kth == 1){
        return min(A[Aidx],B[Bidx]);
    }

    int mid = Kth/2 - 1;
    int Akey = (Aidx + mid) >= A.size() ? INT_MAX : A[Aidx + mid];
    int Bkey = (Bidx + mid) >= B.size() ? INT_MAX : B[Bidx + mid];
    int newKth = Kth- Kth / 2;
    if(Akey < Bkey){  //如果A的k/2-1处元素小于B的k/2-1处的元素，则舍弃B前k/2个元素
        return findKthNumber(A,B,Aidx + Kth / 2,Bidx,newKth);
    }else{
        return findKthNumber(A,B,Aidx,Bidx+Kth / 2,newKth);
    }
}

double Solution4::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2){
    int len = nums1.size() + nums2.size();

    if(len % 2 == 0){
        return (findKthNumber(nums1,nums2,0,0,len/2) + findKthNumber(nums1,nums2,0,0,len/2 + 1)) / 2.0;
    }else{
        return findKthNumber(nums1,nums2,0,0,len/2 + 1);
    }
}




