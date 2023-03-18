#include "437.PathSumIII.h"
#include <unordered_map>

void pathSum(TreeNode* root, const int & targetSum, std::unordered_map<int64_t, int> & mapCnt, int & ans, int64_t pathval) {
    if(root == nullptr) {
        return;
    }

    int64_t sum = pathval + root->val;
    if(sum == targetSum) {
        ++ans;
    }
    auto pIter = mapCnt.find(sum - targetSum);
    if(pIter != mapCnt.end()) {
        ans += pIter->second;
    }
    
    ++mapCnt[sum];
    pathSum(root->left, targetSum, mapCnt, ans, sum);
    pathSum(root->right, targetSum, mapCnt, ans, sum);
    --mapCnt[sum];
}

int pathSum(TreeNode* root, int targetSum) {
    int64_t pathval = 0;
    int ans = 0;
    std::unordered_map<int64_t, int> mapCnt;
    pathSum(root, targetSum, mapCnt, ans, pathval);
    return ans;
}