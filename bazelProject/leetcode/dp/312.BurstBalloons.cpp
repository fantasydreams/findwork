#include "312.BurstBalloons.h"

int maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    int n = nums.size() - 2;
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for(int len = 1; len <= n; ++len) {
        for(int i = 1; i <= n + 1 - len; ++i) {
            int j = i + len - 1;
            for(int k = i; k <= j; ++k) {
                dp[i][j] = max(dp[i][j], dp[i][k - 1] + nums[i - 1] * nums[k] * nums[j + 1] + dp[k + 1][j]);
            }
        }
    }

    return dp[1][n];
}

void backtrace(vector<int> & nums, int score, int & res) {
    if(nums.size() == 2) {
        res = max(res, score);
        return;
    }

    for(int i = 1; i < nums.size() - 1; ++i) {
        int tmp = nums[i];
        int tmpscore = tmp * nums[i - 1] * nums[i + 1];
        nums.erase(nums.begin() + i);
        backtrace(nums, score + tmpscore, res);
        nums.insert(nums.begin() + i, tmp);
    }
}

int maxCoins1(vector<int>& nums) {
    int res = 0;
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    backtrace(nums, 0, res);
    return res;
}

void backtracememo(vector<int> & nums, int left, int right, vector<vector<int>> & memo) {
    if(left > right) {
        return;
    }else if(memo[left][right]) {
        return;
    }

    for(int k = left; k <= right; ++k) {
        backtracememo(nums, left, k - 1, memo);
        backtracememo(nums, k + 1, right, memo);

        memo[left][right] = max(memo[left][right], memo[left][k - 1] + nums[left - 1] * nums[k] * nums[right + 1] + memo[k + 1][right]);
    }
}

int maxCoins2(vector<int>& nums) {
    int res = 0;
    int n = nums.size();
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    backtracememo(nums, 1, n, dp);
    return dp[1][n];
}