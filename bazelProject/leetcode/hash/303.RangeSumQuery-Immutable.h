#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


class NumArray {
public:
    NumArray(vector<int>& nums) {
        leftSum.resize(nums.size() + 1, 0);
        for(int i = 1; i <= nums.size(); ++i) {
            leftSum[i] = leftSum[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return leftSum[right + 1] - leftSum[left];
    }
private:
    vector<int> leftSum;
};

class NumArray1 {
public:
    NumArray1(vector<int>& nums) : leftSum(nums.size() + 1, 0) {
        partial_sum(nums.begin(), nums.end(), leftSum.begin() + 1);
    }
    
    int sumRange(int left, int right) {
        return leftSum[right + 1] - leftSum[left];
    }
private:
    vector<int> leftSum;
};