#include "215.KthLargestElementinanArray.h"
#include <algorithm>
#include <climits>
#include <cmath>
#include <queue>

int findKthLargest(vector<int>& nums, int k)
{
    int l = 0, r = nums.size() - 1, tmp, i, j;
    while(l < r)
    {
        i = l, j = r;
        while(i < j)
        {
            while(i < j && nums[j] <= nums[i]) {
                --j;
            }
            std::swap(nums[j], nums[i]);

            while(i < j && nums[i] >= nums[j]){
                ++i;
            }
            swap(nums[i], nums[j]);
        }

        if(j == k - 1) {
            return nums[j];
        }else if(j > k - 1) {
            r = j - 1;
        }else {
            l = j + 1;
        }
    }

    return nums[r];
}

// 思路： 利用快排，不用完全拍好，只需要排号前面的就行
// 二、堆排序
// 三、sort
 
int findKthLargestSort(vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end(), [](int a, int b){return a > b;});
    return nums[k - 1];
}


int findKthLargestQuickSort(vector<int> &nums, int k) {
    int left = 0, right = nums.size() - 1;
    while(left < right) {
        int i = left, j = right;
        while(i < j) {
            while(i < j && nums[j] <= nums[i]) {
                --j;
            }
            swap(nums[i], nums[j]);

            while(i < j && nums[i] >= nums[j]) {
                ++i;
            }
            swap(nums[i], nums[j]);
        }

        if(j == k - 1) {
            return nums[j];
        }else if(j > k - 1) {
            right = j - 1;
        }else {
            left = j + 1;
        }
    }

    return nums[right];
}


// 

class Compare {
public:
    bool operator() (int a, int b) {
        return a > b;
    }
};

int findKthLargestHeapSort(vector<int> &nums, int k) {
    Compare oCompare;
    std::vector<int> heap(nums.begin(), nums.begin() + k);
    std::make_heap(heap.begin(), heap.end(), oCompare);
    for(int i = k; i < nums.size(); ++i) {
        heap.push_back(nums[i]);
        push_heap(heap.begin(), heap.end(), oCompare);
        pop_heap(heap.begin(), heap.end(), oCompare);
        heap.pop_back();
    }

    int ans = 0;
    // while(!heap.empty()) {

        pop_heap(heap.begin(), heap.end(), oCompare);
        ans = heap.back();
        // heap.pop_back();
    // }
    return ans;
}


int findKthLargestPriQue(vector<int> &nums, int k) {
    std::priority_queue<int, std::vector<int>, Compare> priQue;
    for(const auto& iVal : nums) {
        priQue.push(iVal);
        if(priQue.size() > k) {
            priQue.pop();
        }
    }

    return priQue.top();
}

int findKthLargestPriQue1(vector<int> &nums, int k) {
    std::priority_queue<int, std::vector<int>, Compare> que;
    for(const auto& iNum : nums) {
        que.push(iNum);
        if(que.size() > k) {
            que.pop();
        }
    }

    return que.top();
}
