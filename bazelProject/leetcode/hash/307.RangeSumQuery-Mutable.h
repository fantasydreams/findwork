
#include <vector>
#include <numeric>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) : pSum(nums.size() + 1, 0), origin(nums){
        std::partial_sum(nums.begin(), nums.end(), pSum.begin() + 1);
    }
    
    void update(int index, int val) {
        int diff = val - origin[index];
        for(int i = index + 1; i < pSum.size(); ++i) {
            pSum[i] += diff;
        }
        origin[index] = val;
    }
    
    int sumRange(int left, int right) {
        return pSum[right + 1] - pSum[left];
    }
private:
    vector<int> pSum, origin;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */