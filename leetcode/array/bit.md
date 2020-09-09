# 数组位运算符专题
首先说明一下几个位运算符
+ 按位与（&）运算符
    + 1 & 1 = 1
    + 1 & 0 = 0, 0 & 1 = 0
    + 0 & 0 = 0
+ 按位或(｜)运算符
    + 1 | 1 = 1
    + 1 | 0 = 1, 0 | 1 = 1
    + 0 | 0 = 0
+ 按位异或(^)运算符
    + 1 ^ 1 = 0
    + 1 ^ 0 = 1, 0 ^ 1 = 1
    + 0 ^ 0 = 0  

数组异或的题型，主要包括
+ 给定一个数组，数组中的元素满足：仅有一个元素出现次数为奇数次，其余全为偶数次
+ 给定一个数组，数组中的元素满足：仅有两个元素出现次数为奇数次，其余全为偶数次
+ 给定一个数组，数组中的元素满足：仅有三个元素出现次数为奇数次，其余全为偶数次  
+ 给定一个数组，数组中的元素满足：仅有一个元素出现1次，其余出现3次 

然后题目要求为计算出出现次数为奇数次的元素，这类题目通用但是效率不是最优的解法为：  
hash表暴力统计，普通的hash表统计适合给定元素范围的，如果没给定范围，可采用map+count，key为数组元素值，val为出现的次数，统计完毕后再进行一次遍历hash表或者map，得到出现奇数次的元素
+ 时间复杂度，如果采用hash表，时间复杂度为O(N),map由于底层采用红黑树，查找复杂度为O(logN),故时间复杂度为O(N * logN)，空间复杂度为O(N)

## 仅有一个元素出现次数为奇数次，其余全为偶数次
[136. Single Number](https://leetcode.com/problems/single-number/description/)  

### 解法一
通过位运算符号易知:
+ num ^ num = 0,   num ^ 0 = num
+ num | num = num, num | 0 = num
+ num & num = num, num & 0 = 0

可以发现，对于出现偶数次的数字，异或后的结果为0，出现奇数次 N = even + 1，即可以转化为一个偶数+1个奇数。因此可以对数组中所有的元素进行异或运算，最终得到的结果就是出现奇数次的元素
```C++
int singleNumber(vector<int>& nums) {
    int res = 0;
    for(size_t idx = 0;idx < nums.size();++idx){
        res ^= nums[idx];
    }
    return res;
}
```
+ 时间复杂度O(N)，空间复杂度为O(1)  

## 仅有两个元素出现次数为奇数次，其余全为偶数次
[260. Single Number III](https://leetcode.com/problems/single-number-iii/)  
显然，出现了两个出现次数为奇数的元素，使用直接异或得到的数值为两个数字的异或结果，而直接通过这个异或的结果显然是不能得到两个异或前的元素的，但是由于两个数值不一样，因此一定存在异或后的结果中某一位为1（假设为从右往左的第一位），显然，数组中这一位出现0，1的次数是奇数次,且两个出现奇数次的数分别分布在两个subarray中，在两个subarray中分别异或就能得到需要寻找的数值
### 解
+ 通过异或的值从右往左的第一位1作为划分标准，将原数组中的所有值划分成两个subarray
+ 在两个subarray中分别异或就能得到需要寻找的数值  

```C++
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x_or = 0, f_one_bit = 0;
        for(int i=0;i<nums.size();++i) x_or ^= nums[i];
        f_one_bit = x_or & (~(x_or - 1));
        vector<int> res(2,0);
        for(int i=0;i<nums.size();++i){
            if(nums[i] & f_one_bit) res[0] ^= nums[i];
            else res[1] ^= nums[i];
        }
        return res;
    }
};
```
+ 空间复杂度O(N)，空间复杂度O(1)

[540. Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/)  
+ 二分查找，根据mid奇偶的情况来判断
+ 如果mid是奇数，那么判断前一个元素与自身是否相等，相等则出现一次的元素在后半部分，否则在前半部分
+ 如果mid是偶数，那么判断后一个元素与自身是否相等，相等则出现一次的元素在后半部分，否则在前半部分

```C++
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int left = 0,right = nums.size()-1,mid;
        while(left + 1 < right){
            mid = (left + right) / 2;
            if(mid & 0x1){
                if(nums[mid-1] == nums[mid]) left = mid;
                else right = mid;
            }else{
                if(nums[mid] == nums[mid+1]) left = mid;
                else right = mid;
            }
        }
        
        return nums[right + 1 >= nums.size() ? right :
                    (nums[right] == nums[right + 1] ? left : right)];
    }
};
```
+ 时间复杂度O(logN)，空间复杂度O(1)


## 仅有三个元素出现次数为奇数次，其余全为偶数次
对于有三个数出现了奇数次，如果直接全部异或所有的数值，得到的结果意义不大，有没有一种方式，求出三个数中的任意一个，然后转换为2个数出现次数为奇数的情况
### 解
对于这三个数的任意一位（bit），存在以下情况
+ 均为0
+ 0和1出现的次数，一个为1次，一个为两次
+ 均为1

对于第二种情况，可以发现出现1次的case，就可以划分（按照当前bit是否为1来划分）为数组中某一个数出现了奇数次，其余的为偶数次的情况，剩下的两个异或结果不为零。因此不难推断解法：通过计数当前位为1和为0的数字出现的次数，对当位为1的进行异或结果为xor_A，对为0的进行异或结果为oxr_B，如果是第二种情况，那么出现出现偶数次bit的异或结果一定为非零，此时，返回另一个subarray的异或结果即是三个数中的其中一个
```C++
#define is_one(n, i) ((n) & 1 << (i))
const int len = 32;
int find_anyone(vector<int> &arr){
    for(int i = 0; i < len; i++){
        int tmpA = 0,tmpB = 0, countA = 0,countB = 0;
        for(int j = 0; j < arr.size(); j++){
            if(is_one(arr[j], i)){
                tmpA ^= arr[j];
                countA++;
            }else{
                tmpB ^= arr[j];
                countB++;
            }
        }
        if(countA & 0x1){ //如果出现奇数次
            if(0 == tmpB) continue; //这里说明三个数字的当前bit相同
            else return tmpA; //tmpB不为0说明为0和1出现的次数，一个为1次，一个为两次
        }else{
            if(0 == tmpA) continue;
            else return tmpB;
        }
    }
}
```
+ 空间复杂度O(1),时间复杂度O(N)

## 仅有一个元素出现1次，其余出现3次 
[540. Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/)  
除了一个元素外，其余的出现次数都是3次，那么除了这个元素外，其余的数值所有bit位为1的总和为3的倍数，如果剩下的那个元素当前位如果是1，那么所有数值当前bit出现1的次数为 3 * N + 1  

### 解  
+ 对32位，分别统计出现1的次数count
+ count余3后 |= 到res上，所算即所得

```C++
class Solution {
    const int len = 32;
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0;i<len;++i){
            int count = 0;
            for(size_t j = 0;j < nums.size();++j)count += (nums[j] >> i & 0x1);
            res |= ((count % 3) << i);
        }
        return res;
    }
};
```
+ 时间复杂度O(N)，空间复杂度O(1)



