# 从数组中寻找寻找特定组合
## 从数组中找到和为指定target的序列

这类题型往往是给定一个数组，要求从数组中找到k（k=1,2,3,...）个元素和为target的序列，求解可以是找到指定序列的下标id。

### 从给定数组中找到key

常见的题型，主要包括：
+ 给定一个数组，查找key是否在数组中
+ 给定循环递增数组，从数组中找到最小值，或者找给定的key是否存在于这个循环数组中。

#### 循环数组最小值
[153. Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)  
+ special case：整个数组是有序的，这时候只需要返回第一个元素即可 （本题不考虑空数组的情况）
+ 除了special case，那么最小值一定在数组中间，这时利用二分来判断，如果nums[left] < numsp[mid]则此部分一定是有序的，最小值在另一部分。
+ 这里没有采用二分当中的left = mid + 1和right = mid -1，是为了将最小值限制在数组中间。
```C++
int findMin(vector<int>& nums) {
	size_t left = 0,right = nums.size()-1,mid;
	if(nums.size() == 1) return nums[left];
	if(nums[left]  < nums[right]) return nums[left];
	while(left + 1 < right){
		mid = (left + right)/2;
		if(nums[mid] > nums[left]){ //left is sorted subarray
			left = mid;
		}else right = mid;
	}
	return nums[right];
}
```
[154. Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)  
+ 对于有重复元素的循环数组，special case如[0,0,0,-1,0],[1,1,2,1,1]等类似的用例，是没办法通过二分的方式查找的，只能顺序查找，除了原始用例这样的，还有可能通过二分划分之后subarray也是这种情况,因此这部分代码放在二分划分当中
+ special case：nums[0] < nums[size - 1]，这时候只需要返回第一个元素即可  
```C++
int findMin(vector<int>& nums) {
        size_t left = 0,right = nums.size()-1,mid;   
        if(nums[left] < nums[right]) return nums[left];
        while(left + 1 < right){
            if(nums[left] == nums[right]) return find_bysquence(nums,left,right);
            mid = (left + right)/2;
            if(nums[mid] >= nums[left]){ //left is sorted subarray
                left = mid;
            }else right = mid;
        }
        return nums[right];
    }
```
+ 平均时间复杂度O(log N)，最差时间复杂度为O(N)，空间复杂度O(1)

#### 循环数组找特定值  
[33.Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array)  
容易想到的办法是直接遍历数组判断是否存在相同的数值，时间复杂度为O(N),很明显没有利用好循环递增数组的特定。  

+ 思路一
	+ 找循环数组最小值，划分为两个有序递增数组
	+ 在两个递增序列中进行二分查找

+ 思路二
	+ 直接利用二分查找的思路去判断，如arr[left] <= arr[mid]，说明此部分一定是递增的，然后判定target是否在区间内，不在则更新查找区间为后半部分。  


```C++
int search(vector<int>& nums, int target) {
	if(nums.size() == 0) return -1;
	
	int left = 0,right = nums.size()-1,mid;
	while(left <= right){
		mid = (left + right) / 2;
		if(nums[mid] == target) return mid;
		if(nums[left] <= nums[mid]){
			if(nums[left] <= target && target <= nums[mid]) right = mid -1;
			else left = mid + 1;
		}else{
			if(nums[mid] <= target && target <= nums[right]) left = mid + 1;
			else right = mid-1;
		}
	}
	
	return -1;
}
```
+ 空间复杂度O(logN)，时间复杂度为O(1)  
[81. Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)  
+ 由于存在重复元素，因此不能使用上题的思路二，但是可以采用思路一
+ special case:[0,1,2,3,0,0,0,0]，通过找到第二个有序数组的最小值的下标，将他们切分成两个有序数组即[0,1,2,3],[0,0,0,0],再分别二分

### 从数组中找N-sum
这类题目主要分为  
+ 2-sum
+ 3-sum
+ 4-sum
+ k-sum / combine-sum
+ k-close

题目大意基本都是给定一个数组，和一个sum,从数组中找到k个元素和为sum的组合（一般需要组合不重复）  

### 2-sum
[1. Two Sum](https://leetcode.com/problemset/all/)  
数组可以分为两种情况，一种是经过排序的，一种是无序的,主要解法分为以下几种  
+ 暴力解法，挑选好一个元素nums[i]后，遍历数组是是否存在nums[j] == sum-nums[i], 空间复杂度O(1)，时间复杂度O(N^2)  
+ hash_map，遍历数组的同时查寻sum-nums[i]是否在map中，如果不再将nums[i]插入到map中，空间复杂度O(N)，时间复杂度map:O(logN),unordered_map:O(N)  
+ 先排序，遍历，每遍历一个元素的同时，对数组进行二分查找。时间复杂度O(nlogn)，空间复杂度O(1)
+ 先排序，然后双指针start和end，如果nums[start] + nums[end] < sum 则++start ,nums[start] + nums[end] > sum 则--end，若相等则返回。时间复杂度为O(nlogn)，空间复杂度为O(1)

### 3-sum
[3.Sum](https://leetcode.com/problems/3sum/)
+ 暴力，时间复杂度O(n^3)  
+ 排序，3个指针移动，start,mid,end,其中 0<=start < mid < end <= nums.size()-1，时间复杂度O(n^2)  
+ 排序，然后双指针i,j,然后通过二分查找查找target - nums[i] - nums[j]，但是有一个缺点是导致元素的重复使用。时间复杂度为O(n^2)  

### 4-sum
[18. 4Sum](https://leetcode.com/problems/4sum/)  
+ 暴力，时间复杂度O(n^4)
+ 排序，四指针或者分解成3-sum->2-sum，时间复杂度O(n^3)

```C++
class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums,int start, int target) {
        int end = nums.size()-1;
        vector<vector<int>> res;
        while(start < end){
            int sum = nums[start] + nums[end];
            if(sum < target)++start;
            else if(sum > target) --end;
            else{
                res.push_back(vector<int>{nums[start],nums[end]});
                while(--end > start && nums[end] == nums[end+1]);
                while(end > ++start && nums[start] == nums[start-1]);
            }
        }
        return res;
    }
    vector<vector<int>> threeSum(vector<int>& nums,int start,int target) {
        vector<vector<int>> res;
        int end = nums.size()-1;
        while(start + 2 <= end){
            vector<vector<int>> two = twoSum(nums,start+1,target-nums[start]);
            for(int j=0;j<two.size();++j){
                two[j].insert(two[j].begin(),nums[start]);
                res.push_back(two[j]);
            }
            while(++start < end && nums[start]==nums[start-1]);
        }
        return res;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int start = 0,end = nums.size()-1;
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        while(start + 3 <= end){
            vector<vector<int>> three = threeSum(nums,start+1,target-nums[start]);
            for(int i=0;i<three.size();++i){
                three[i].insert(three[i].begin(),nums[start]);
                res.push_back(three[i]);
            }
            while(++start < end && nums[start] == nums[start-1]);
        }
        return res;
    }
};
```

### k-sum / combine-sum
[39. Combination 4-sum](https://leetcode.com/problems/combination-sum/)  
[40. Combination Sum II](https://leetcode.com/problems/combination-sum/)  
对于此类题目的通用解法，采用简单的0-1背包+回溯剪枝

+ 对数组进行排序
+ 当前数字nums[i]分为两种情况：加入背包和放弃加入背包，若加入背包，背包数字数字数量n+=1，sum = old_sum + nums[i];
+ 判断sum == target，k== n,如果条件成立则当前背包中的数字集合即为结果之一







