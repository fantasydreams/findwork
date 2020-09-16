//
// Created by sharwen on 2020/3/15.
//

#ifndef C___LEETCODE_EN_H
#define C___LEETCODE_EN_H
#include "../type.h"


class Solution31 {
public:
    void nextPermutation(vector<int>& nums) {
        auto i = nums.end() - 1;
        while(i!= nums.begin()){ //注意检查边界条件
            auto after = i;
            if(*after > *--i){
                auto j = nums.end();
                while(*i >= *--j);
                swap(*i, *j);
                reverse(after, nums.end());
                return;
            }

            if(i == nums.begin()){
                reverse(nums.begin(),nums.end());
                return;
            }
        }
    }
};

//双指针 11. Container With Most Water
class Solution11 {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size()-1;
        int max_val = INT_MIN;
        while(start < end){
            int area = (end - start) * min(height[start],height[end]);
            if(area > max_val) max_val = area;
            if(height[start] > height[end]) --end;
            else if(height[start] < height[end]) ++ start;
            else{
                ++start;
                --end;
            }
        }

        return max_val;
    }
};

//三指针 16. 3Sum Closest
class Solution16 {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());
        int min_abs = INT_MAX;
        int res = 0;

        for(int i = 0;i < nums.size() && res != target;++i){
            int start = i + 1;
            int end = nums.size()-1;
            while(start < end){
                int sum = nums[i] + nums[start] + nums[end];
                if(sum == target){
                    res = sum;
                    break;
                }else {
                    if(abs(sum - target) < min_abs){
                        min_abs = abs(sum - target);
                        res = sum;
                    }
                    if(sum < target) ++start;
                    else --end;
                }
            }
        }

        return res;
    }
};

class Solution_236_a {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q) return nullptr;
        if(root == p || root == q) return root;
        TreeNode * left = lowestCommonAncestor(root->left,p,q);
        TreeNode * right = lowestCommonAncestor(root->right,p,q);
        if(left && right) return root;
        else if(left) return left;
        else if(right) return right;
        else return nullptr;
    }
};

class Solution_236 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *>p_ans,q_ans;
        get_ancestor_path(root,p_ans,p);
        get_ancestor_path(root,q_ans,q);
        int len = min(p_ans.size(),q_ans.size());
        TreeNode * res = nullptr;
        for(int i =0;i < len && p_ans[i] == q_ans[i];++i)res = p_ans[i];
        return res;
    }

    bool get_ancestor_path(TreeNode * root,vector<TreeNode *> &path,  TreeNode * p){
        if(!root) return false;
        path.push_back(root);
        if(root == p) return true;
        bool res = get_ancestor_path(root->left,path,p);
        if(!res) res = get_ancestor_path(root->right,path,p);
        if(!res) path.pop_back();
        return res;
    }
};

class Solution_235 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q) return nullptr;
        if(p->val > q->val)swap(p,q);

        while(root){
            if(root->val < p->val) root = root->right;
            else if(root->val > q->val)root = root->left;
            else return root;
        }
        return nullptr;
    }
};

class Solution_590_b {
public:
    vector<int> postorder(f_Node* root) {
        stack<pair<f_Node*,int>> st;
        vector<int> res;
        if(root==NULL) return res;
        st.push(pair<f_Node*,int>(root,0));
        while(!st.empty())
        {
            auto &[node,idx] = st.top();
            if(idx == node->children.size()){
                res.push_back(node->val);
                st.pop();
            }else st.push(pair<f_Node *,int>(node->children[idx++],0));
        }
        return res;
    }
};

class Solution_590_a {
public:
    vector<int> postorder(f_Node* root) {

        stack<f_Node*> st;
        vector<int> res;
        if(root==NULL) return res;
        st.push(root);
        while(!st.empty())
        {
            f_Node* node = st.top();
            st.pop();
            res.push_back(node->val);
            for(int i=0;i<node->children.size();i++) st.push(node->children[i]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

class Solution_590 {
public:
    vector<int> postorder(f_Node* root) {
        vector<int> res;
        post_order(root,res);
        return res;
    }

    void post_order(f_Node *root,vector<int> &res){
        if(!root)return;
        for(int i=0;i<root->children.size();++i)post_order(root->children[i],res);
        res.push_back(root->val);
    }
};

class Solution_589 {
public:
    vector<int> preorder(f_Node* root) {
        vector<int> res;
        if(!root) return res;
        stack<f_Node *> st;st.push(root);
        while(!st.empty()){
            f_Node * node = st.top();st.pop();
            res.push_back(node->val);
            if(node->children.size()){
                for(int i=node->children.size()-1;i>=0;--i){
                    st.push(node->children[i]);
                }
            }
        }
        return res;
    }
};

class Solution_429 {
public:
    vector<vector<int>> levelOrder(f_Node* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<f_Node *> q;q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size;++i){
                f_Node *node = q.front();q.pop();
                level.push_back(node->val);
                if((node->children).size()){
                    for(int i=0;i<(node->children).size();++i){
                        q.push((node->children)[i]);
                    }
                }
            }
            res.push_back(level);
        }
        return res;
    }
};

class Solution_103 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode *> q;q.push(root);
        bool flag = false;
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size;++i){
                TreeNode *node = q.front();q.pop();
                level.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(flag)reverse(level.begin(),level.end());
            flag = !flag;
            res.push_back(level);
        }
        return res;
    }
};

class Solution_637 {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(!root) return res;
        queue<TreeNode *> q;q.push(root);
        while(!q.empty()){
            int size = q.size();
            double sum = 0;
            for(int i=0;i<size;++i){
                TreeNode *node = q.front();q.pop();
                sum+=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            res.push_back((sum/size));
        }
        return res;
    }
};

class Solution_107 {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode *> q;q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size;++i){
                TreeNode *node = q.front();q.pop();
                level.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            res.push_back(level);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

class Solution_102 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode *> q;q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size;++i){
                TreeNode *node = q.front();q.pop();
                level.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            res.push_back(level);
        }
        return res;
    }
};

class Solution_230 {
    void push_left_util_null(TreeNode * root,stack<TreeNode *> &st){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> st;
        push_left_util_null(root,st);
        while(!st.empty()){
            TreeNode* node = st.top();st.pop();
            if(k-- == 1)return node->val;
            if(node->right)push_left_util_null(node->right,st);
        }
        return 0;
    }

};

class BSTIterator_173_a {
private:
    stack<TreeNode *>st;

    void push_left_util_null(TreeNode * root,stack<TreeNode *> &st){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
public:
    BSTIterator_173_a(TreeNode* root) {
        push_left_util_null(root,st);
    }

    /** @return the next smallest number */
    int next() {
        TreeNode * node = st.top();st.pop();
        if(node->right)push_left_util_null(node->right,st);
        return node->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};

class BSTIterator_173 {
private:
    TreeNode * t_root;
    void convert2list(TreeNode *root, TreeNode * &pre){
        stack<TreeNode *> st;
        push_left_util_null(root,st);
        while(!st.empty()){
            TreeNode * node = st.top();st.pop();
            if(pre)pre->right = node;
            node->left = pre;
            pre = node;
            node = node->right;
            push_left_util_null(node,st);
        }
    }

    void push_left_util_null(TreeNode * root,stack<TreeNode *> &st){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
public:
    BSTIterator_173(TreeNode* root) {
        if(!root){
            t_root = nullptr;
            return;
        }
        TreeNode * pre = nullptr;
        convert2list(root,pre);
        while(root->left)root = root->left;
        t_root = root;
    }

    /** @return the next smallest number */
    int next() {
        int val = t_root->val;
        t_root=t_root->right;
        return val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return t_root != nullptr;
    }
};

class Solution_145_b {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode *> st;st.push(root);
        while(!st.empty()){
            TreeNode * node = st.top();st.pop();
            res.push_back(node->val);
            if(node->left)st.push(node->left);
            if(node->right)st.push(node->right);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

class Solution_145_a {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode *> st;
        push_left_until_null(root,st);
        TreeNode * pre = nullptr;
        while(!st.empty()){
            TreeNode * node = st.top();
            if(node->right){
                if(node->right == pre){
                    res.push_back(node->val);
                    st.pop();
                    pre = node;
                }else {
                    node = node->right;
                    push_left_until_null(node,st);
                }
            }else {
                res.push_back(node->val);
                st.pop();
                pre = node;
            }
        }
        return res;
    }

    void push_left_until_null(TreeNode * root,stack<TreeNode *> & st){
        while(root){
            st.push(root);
            root=root->left;
        }
    }

};

class Solution_145 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        post_order(root,res);
        return res;
    }

    void post_order(TreeNode *root,vector<int> &res){
        if(!root) return;
        post_order(root->left,res);
        post_order(root->right,res);
        res.push_back(root->val);
    }
};

class Solution_144_a {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)return res;
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()){
            TreeNode * node = st.top();
            st.pop();
            res.push_back(node->val);
            if(node->right)st.push(node->right);
            if(node->left)st.push(node->left);
        }
        return res;
    }
};

class Solution_144 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        pre_order(root,res);
        return res;
    }

    void pre_order(TreeNode * root,vector<int> &res){
        if(!root) return;
        res.push_back(root->val);
        pre_order(root->left,res);
        pre_order(root->right,res);
    }
};

class Solution_94_a {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        vector<int> res;
        push_left_util_null(root,st);
        while(!st.empty()){
            TreeNode * node = st.top();st.pop();
            res.push_back(node->val);
            node = node->right;
            push_left_util_null(node,st);
        }
        return res;
    }

    void push_left_util_null(TreeNode * root,stack<TreeNode *> &st){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
};

class Solution_94 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        in_order(root,res);
        return res;
    }

    void in_order(TreeNode* root,vector<int> &res){
        if(!root) return;
        in_order(root->left,res);
        res.push_back(root->val);
        in_order(root->right,res);
    }
};

class Solution_6 {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        vector<string> matrix(numRows);
        int idx = 0,flag = 1;
        for(int i=0;i<s.size();++i){
            matrix[idx] += s[i];

            if(idx == 0)flag = 1;
            if(idx == numRows-1)flag = -1;
            idx += flag;
        }

        string res;
        for(int i =0;i<matrix.size();++i)res += matrix[i];
        return res;
    }
};

class Solution_494_a {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 0) return 0;
        unordered_map<int,int> dp;
        ++dp[nums[0]],++dp[-nums[0]];
        for(int i=1;i<nums.size();++i){
            unordered_map<int,int> next;
            for(auto iter = dp.begin();iter != dp.end();++iter){
                next[iter->first + nums[i]] += iter->second;
                next[iter->first - nums[i]] += iter->second;
            }
            dp = next;
        }
        return dp[S];
    }
};

class Solution_494 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res = 0;
        dfs(nums,0,res,0,S);
        return res;

    }

    void dfs(vector<int> & nums,int idx,int& res,int cur_sum,int sum){
        if(idx >= nums.size()){
            if(cur_sum == sum) ++res;
            return;
        }

        dfs(nums,idx+1,res,cur_sum + nums[idx],sum);
        dfs(nums,idx+1,res,cur_sum - nums[idx],sum);
    }
};

class Solution_18_a {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int start = 0,end_f = nums.size()-1;
        while(start + 3 <= end_f){
            int left = start + 1,end_th = nums.size()-1;
            while(left + 2 <=end_th){
                int right = left + 1,end_tw = nums.size()-1;
                while(right + 1 <= end_tw){
                    int sum = nums[start] + nums[left] + nums[right] + nums[end_tw];
                    if(sum < target)++right;
                    else if(sum > target)--end_tw;
                    else {
                        res.push_back({nums[start],nums[left],nums[right],nums[end_tw]});
                        while(--end_tw > right && nums[end_tw] == nums[end_tw+1]);
                        while(++right < end_tw && nums[right] == nums[right-1]);
                    }
                }
                while(++left < end_th && nums[left] == nums[left-1]);
            }
            while(++start < end_f && nums[start] == nums[start-1]);
        }
        return res;
    }
};

class Solution_18 {
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


class Solution_653 {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        in_order(root,arr);
        int left = 0,right = arr.size()-1;
        while(left < right){
            int sum = arr[left] + arr[right];
            if(sum < k) ++left;
            else if(sum > k) --right;
            else return true;
        }
        return false;
    }

    void in_order(TreeNode * root, vector<int> & res){
        if(!root)return;
        in_order(root->left,res);
        res.push_back(root->val);
        in_order(root->right,res);
    }
};

class Solution_260 {
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

class Solution_540 {
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

class Solution_137 {
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

class Solution_81 {
public:
    int find_bysquence(vector<int> & arr,int left,int right){
        int _min_idx = left;
        for(size_t i = left+1;i<right;++i){
            if(arr[i-1] > arr[i]) _min_idx = i;
        }
        return _min_idx;
    }

    int findMin(vector<int>& nums) {
        int left = 0,right = nums.size()-1,mid;
        if(nums[left] < nums[right]) return left;
        while(left + 1 < right){
            if(nums[left] == nums[right]) return find_bysquence(nums,left,right);
            mid = (left + right)/2;
            if(nums[mid] >= nums[left]){ //left is sorted subarray
                left = mid;
            }else right = mid;
        }

        return right;
    }

    bool binary_search(vector<int> & nums,int left,int right,int target){
        if(left > right) return false;
        int mid;
        while(left <= right){
            mid = (left + right) /2;
            if(nums[mid] < target) left = mid + 1;
            else if(nums[mid] > target) right = mid - 1;
            else return true;
        }

        return false;
    }

    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) return false;
        int min_idx = findMin(nums);
        bool res = binary_search(nums,0,min_idx-1,target);
        if(!res) res = binary_search(nums,min_idx,nums.size()-1,target);

        return res;
    }
};


class Solution_33_2 {
public:

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
};

class Solution_33_1 {
public:

    int binary_search(vector<int> & nums,int left,int right,int target){
        if(left > right) return -1;
        int mid;
        while(left <= right){
            mid = (left + right) /2;
            if(nums[mid] < target) left = mid + 1;
            else if(nums[mid] > target) right = mid - 1;
            else return mid;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        if(nums.size() == 1) return ((nums[0] == target) ? 0 : -1);
        if(nums[0] < nums[nums.size()-1]) return binary_search(nums,0,nums.size()-1,target);
        size_t left = 0,right = nums.size()-1,mid;
        while(left + 1 < right){
            mid = (left + right) /2;
            if(nums[mid] > nums[left]) left = mid;
            else right = mid;
        }

        if(nums[0]<=target && target <= nums[right-1])
            return binary_search(nums,0,right-1,target);
        if(nums[right]<=target && target <= nums[nums.size()-1])
            return binary_search(nums,right,nums.size()-1,target);
        return -1;
    }
};

class Solution_153 {
public:
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
};

class Solution_154 {
public:

    int find_bysquence(vector<int> & arr,int left,int right){
        int _min = arr[0];
        for(size_t i = left;i<right;++i){
            if(arr[i] < _min) _min = arr[i];
        }
        return _min;
    }
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
};

class Solution_216 {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if(k<=0 || n <=0) return res;

        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        vector<int> tmp;
        dfs(arr,res,tmp,0,k,n);
        return res;
    }

    void dfs(vector<int> &arr,vector<vector<int>> &res,
             vector<int> &tmp,int idx,int k,int sum){
        if(sum == 0 && k == 0){
            res.push_back(tmp);
            return;
        }
        if(k < 0 || idx >= arr.size() || sum < arr[idx]) return;

        for(size_t start = idx;start < arr.size();++start){
            tmp.push_back(arr[start]);
            dfs(arr,res,tmp,start+1,k-1,sum - arr[start]);
            tmp.pop_back();
        }
    }
};

class Solution_40 {
public:

    bool _equal(vector<int> & a,vector<int> & b){
        if(a.size() != b.size()) return false;
        for(int i=0;i<a.size();++i){
            if(a[i] != b[i]) return false;
        }
        return true;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,res,tmp,0,target);
        return res;
    }

    void dfs(const vector<int>& candidates,vector<vector<int>> &res,
             vector<int> &tmp,int idx,int val){
        if(val == 0){
            res.push_back(tmp);
            return;
        }
        if(idx >= candidates.size() || val < candidates[idx]) return;

        for(size_t start = idx;start < candidates.size();++start){
            if(idx != start && candidates[start-1] == candidates[start])continue;
            tmp.push_back(candidates[start]);
            dfs(candidates,res,tmp,start+1,val - candidates[start]);
            tmp.pop_back();
        }
    }
};

class Solution_40_1 {
public:

    bool _equal(vector<int> & a,vector<int> & b){
        if(a.size() != b.size()) return false;
        for(int i=0;i<a.size();++i){
            if(a[i] != b[i]) return false;
        }
        return true;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,res,tmp,0,target);
        sort(res.begin(),res.end());
        auto iter = unique(res.begin(),res.end());
        res.erase(iter,res.end());
        return res;
    }

    void dfs(const vector<int>& candidates,vector<vector<int>> &res,
             vector<int> &tmp,int idx,int val){
        if(val == 0){
            res.push_back(tmp);
            return;
        }
        if(idx >= candidates.size() || val < 0) return;

        tmp.push_back(candidates[idx]);
        dfs(candidates,res,tmp,idx+1,val - candidates[idx]);
        tmp.pop_back();

        dfs(candidates,res,tmp,idx+1,val);
    }
};

class Solution_1044_{
public:
    string longestDupSubstring(string S) {
        if(S.size() == 0) return "";
        vector<string> s_arr;
        for(size_t i =0;i<S.size();++i){
            s_arr.push_back(S.substr(i,S.size()-i));
        }

        string res;
        sort(s_arr.begin(),s_arr.end());
        for(int i=0;i<s_arr.size()-1;++i){
            size_t len = LCA(s_arr[i],s_arr[i+1]);
            if(res.size() < len) res = s_arr[i].substr(0,len);
        }

        return res;
    }


    size_t LCA(string &s1,string &s2){
        if(s1.size() ==0 || s2.size() == 0) return 0;

        size_t res = 0,len=min(s1.size(),s2.size());
        for(size_t i =0;i<len && s1[i] == s2[i];++i)++res;

        return res;
    }
};

class Solution_76 {
public:
    string minWindow(string s, string t) {
        if(s.size() == 0 || t.size() == 0) return "";

        vector<int> sc(256,0),dc(256,0);
        for(int i=0;i<t.size();++i){
            ++dc[t[i]];
        }

        size_t start = 0,found = 0;
        size_t _s = -1,_len = INT_MAX;
        for(size_t i=0;i<s.size();++i){
            ++sc[s[i]];
            if(sc[s[i]] <= dc[s[i]]) ++found;
            if(found == t.size()){
                while(sc[s[start]] > dc[s[start]]){
                    --sc[s[start]];
                    ++start;
                }

                if(i - start + 1 < _len){
                    _s = start;
                    _len = i-start+1;
                }

                --sc[s[start]];
                ++start;
                --found;
            }
        }
        if(_s == -1) return "";
        return s.substr(_s,_len);
    }
};


class Solution_142 {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return nullptr;

        ListNode * slow = head->next,*fast;
        if(!slow) return nullptr;
        fast = slow ->next;
        while(slow && fast && fast->next && (slow != fast)){
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
        }

        fast = head;
        while(slow && fast && fast != slow){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

class Solution_5 {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0) return "";

        string newstr = "@";
        for(int i=0;i<s.size();++i){
            newstr += "#";
            newstr += s[i];
        }
        newstr += "#$";

        int max_len = 0,_max_idx = 0;
        vector<int> p(newstr.size(),0);
        int _max = 0,id = 0;
        for(int i=1;i<newstr.size()-1;++i){
            p[i] = _max >= i ? min(p[2*id - i],_max - i) : 1;
            while(newstr[i + p[i]] == newstr[i-p[i]]) ++p[i];
            if(i + p[i] > _max){
                id = i;
                _max = i + p[i];
            }

            if(p[i] > p[_max_idx]) _max_idx = i;
        }

        string res;
        for(int s=_max_idx - p[_max_idx] + 1,e = _max_idx + p[_max_idx] ;s < e;++s){
            if(newstr[s]!='#')res += newstr[s];
        }

        return res;

    }
};

class Solution_113 {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int>c;
        vector<vector<int>> v;
        findPaths(root,sum,v,c);
        return v;
    }
    void findPaths(TreeNode* root,int sum,vector<vector<int>>& v,vector<int> &c)
    {
        if(!root) return;
        c.push_back(root->val);
        if(!root->left and !root->right){
            if(sum-root->val==0)
                v.push_back(c);
            c.pop_back();
            return;
        }
        if(root->left)
            findPaths(root->left,sum-root->val,v,c);
        if(root->right)
            findPaths(root->right,sum-root->val,v,c);
        c.pop_back();
    }
};

class Solution_142_1 {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode *,int> map;
        bool res = false;
        ListNode * node = head;
        ListNode * p = nullptr;
        int idx = -1;
        for(int i=0;node;++i,node = node ->next){
            map[node] = i;
            if(map.find(node->next) != map.end()){
                res = true;
                idx = map[node->next];
                p = node->next;
                break;
            }
        }

        if(res)cout << "tail connects to node index " << idx;
        else cout << "no cycle";
        return p;
    }
};

class Solution_141 {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode * slow = head, *fast = head->next;
        while(fast && fast != slow){
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        }

        if(fast == nullptr) return false;
        return true;
    }
};

class Solution_437 {
public:
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        pre_order(root,sum,res);
        return res;
    }

    void pre_order(TreeNode *root,int sum,int &res){
        if(!root) return;
        pre(root,sum,res);
        pre_order(root->left,sum,res);
        pre_order(root->right,sum,res);
    }

    void pre(TreeNode* root,int sum,int &res){
        if(!root) return;
        sum -= root->val;
        if(0 == sum) ++res;
        pre(root->left,sum,res);
        pre(root->right,sum,res);
    }
};

class Solution_112 {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        return hasPathSum(root,sum,0);
    }

    bool hasPathSum(TreeNode* root, int sum,int _cur) {
        if(!root) return false;
        if(!root->left && !root->right){
            if(sum == _cur + root->val)return true;
            return false;
        }

        _cur += root->val;
        bool res = hasPathSum(root->left,sum,_cur);
        if(!res) res = hasPathSum(root->right,sum,_cur);
        return res;

    }
};

class Solution_64 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<long>> dp(grid.size(),vector<long int>(grid[0].size(),0));


        return dfs(grid,grid.size()-1,grid[0].size()-1,dp);
        int a= 1;
    }

    int dfs(vector<vector<int>>& grid,int line,int col,vector<vector<long>>&dp){
        if(line < 0 || col < 0) return INT_MAX;
        if(dp[line][col] == 0){
            if(line == 0 && col == 0)dp[line][col] = grid[line][col];
            else dp[line][col] = min(dfs(grid,line,col-1,dp),dfs(grid,line-1,col,dp)) + grid[line][col];
        }
        return dp[line][col];
    }


};

class Solution_stock {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int _min = INT_MAX;
        dfs(grid,0,0,_min,0);
        return _min;
    }

    void dfs(vector<vector<int>>& grid,int line,int col,int &_min,int _cur){
        if(line < 0 || line >= grid.size() || col < 0 || col >= grid[0].size()) return;
        if(line == grid.size()-1 && col == grid[line].size()-1 && _cur < _min){
            _min = _cur;
        }
        _cur += grid[line][col];
        dfs(grid,line+1,col,_min,_cur);
        dfs(grid,line,col+1,_min,_cur);
        _cur -= grid[line][col];
    }
};





class Solution_122 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int _max = 0;

        for(int i=1;i<prices.size();++i){
            if(prices[i] > prices[i-1]){
                _max += prices[i] - prices[i-1];
            }
        }
        return _max;
    }
};

class Solution_543 {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int _max = 0;
        post(root,_max);
        return _max;
    }

    int post(TreeNode * root,int &_max){
        if(!root) return 0;
        int left = post(root->left,_max);
        int right = post(root->right,_max);
        if(left + right > _max) _max = left + right;
        return max(left,right) + 1;
    }
};

class Solution_124 {
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = root->val;
        find_max_path(root,max_sum);
        return max_sum;
    }

    int find_max_path(TreeNode *root,int &max_sum){
        if(!root) return 0;

        int left = find_max_path(root->left,max_sum);
        int right = find_max_path(root->right,max_sum);

        int stop = root->val + max(0,left) + max(0,right);
        int recur = root->val + max(0,max(left,right));
        max_sum = max(max_sum,max(stop,recur));
        return recur;
    }
};

//class Solution_236 {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        vector<vector<TreeNode*>> path(2);
//        bool p_find = false,q_find=false;
//        find_path(root,p,q,path,p_find,q_find);
//
//        int len = min(path[0].size(),path[1].size());
//
//        TreeNode * res;
//        for(int i =0 ; i< len && path[0][i] == path[1][i];++i)res = path[0][i];
//        return res;
//    }
//
//    void find_path(TreeNode *root,TreeNode *p,TreeNode *q,
//                   vector<vector<TreeNode*>> &path,bool &p_find,bool &q_find){
//        if(!root) return;
//        if(!p_find){
//            path[0].push_back(root);
//            if(root == p) p_find = true;
//        }
//
//        if(!q_find){
//            path[1].push_back(root);
//            if(root == q) q_find = true;
//        }
//
//        if(p_find && q_find) return;
//
//        find_path(root->left,p,q,path,p_find,q_find);
//        find_path(root->right,p,q,path,p_find,q_find);
//
//        if(!p_find) path[0].pop_back();
//        if(!q_find) path[1].pop_back();
//    }
//
//    TreeNode * create_tree(vector<int> & arr){
//        TreeNode * root = nullptr;
//        for(int i=0;i < arr.size();++i){
//            insert_tree(root,arr[i]);
//        }
//        return root;
//    }
//
//    TreeNode * insert_tree(TreeNode * &root, int num){
//        if(!root) {
//            root = new TreeNode(num);
//            return root;
//        }else{
//            if(num > root->val) return insert_tree(root->right,num);
//            else return insert_tree(root->left,num);
//        }
//    }
//
//    TreeNode * find_node(TreeNode * root,int num){
//        if(!root) return nullptr;
//        if(root->val == num) return root;
//        else if(root->val > num) return find_node(root->left,num);
//        else return find_node(root->right,num);
//    }
//};

class Solution_98 {
public:
    bool isValidBST(TreeNode* root) {
        long int _first = (long int)INT_MIN - 1;
        return isValidBST(root,_first);
    }

    bool isValidBST(TreeNode* root,long int &_left){
        if(!root) return true;
        bool res = isValidBST(root->left,_left);
        if(!res) return res;
        if(_left >= root->val) return false;
        _left = root->val;
        return isValidBST(root->right,_left);
    }
};


enum color{
    red,
    black,
};

class trie_node{
public:
    trie_node():c(red){}
    color c;
    unordered_map<char,trie_node*> list;
};



class Trie {
public:
    /** Initialize your data structure here. */

    Trie() {
        root = new trie_node;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {

        trie_node * ins = root;
        for(int i = 0;i<word.size();++i){
                auto iter = ins->list.find(word[i]);
                if( iter == ins->list.end()){

                    trie_node * node = new trie_node();

                    (ins->list)[word[i]] = node;
                }
                if(i == word.size()-1) (ins->list)[word[i]]->c = black;
                ins = (ins->list)[word[i]];
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        trie_node * node = root;
        for(int i=0;i<word.size();++i){
            auto iter = node->list.find(word[i]);
            if(iter!=node->list.end()){
                node = iter->second;
                if(i == word.size()-1 && node->c != black) return false;
            }else{
                return false;
            }
        }

        return true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        trie_node * node = root;
        for(int i=0;i<prefix.size();++i){
            auto iter = node->list.find(prefix[i]);
            if(iter!=node->list.end())node = iter->second;
            else return false;
        }

        return true;
    }

private:
    trie_node * root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class Solution_200 {
    bool * is_visited;
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        is_visited = new bool[grid.size() * grid[0].size()];
        memset(is_visited,0,grid.size() * grid[0].size());

        int n_iland = 0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                bool is_iland = false;
                dfs(grid,i,j,is_iland);
                n_iland += is_iland;
            }
        }
        return n_iland;

    }

    void dfs(vector<vector<char>>& grid,int line,int col,bool & iland){
        if(line <0 || line >= grid.size() || col < 0 ||
           col >= grid[line].size() || grid[line][col] == '0') return;
        if(is_visited[line* grid[line].size() + col] == true) return;

        if(is_visited[line* grid[line].size() + col] == false){
            is_visited[line* grid[line].size() + col] = true;
            iland = true;
        }

        dfs(grid,line-1,col,iland);
        dfs(grid,line+1,col,iland);
        dfs(grid,line,col-1,iland);
        dfs(grid,line,col+1,iland);
    }

    Solution_200():is_visited(nullptr){}
    ~Solution_200(){
        if(is_visited) delete is_visited;
    }
};

class Solution_547 {
    vector<int> parent;
    int find_parent(int son){
        int root = parent[son];
        while(root != parent[root]){
            root = parent[root];
        }

        while(parent[son] != root){
            int tmp = parent[son];
            parent[tmp] = root;
            son = tmp;
        }

        return root;
    }

    void _union(int a,int b){
        parent[find_parent(a)] = find_parent(b);
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        parent.resize(M.size());
        for(int i=0;i<M.size();++i)parent[i] = i;
        for(int i=0;i<M.size();++i){
            for(int j=i;j<M.size();++j){
                if(M[i][j]){
                    _union(i,j);
                }
            }
        }

        int g = 0;
        for(int i=0;i<M.size();++i){
            if(parent[i] == i)++g;
        }
        return g;
    }
};

class Solution_721 {
private:
    vector<int> parent;

    int find_parent(int son){
        int root = parent[son];
        while(root != parent[root]){
            root = parent[root];
        }

        while(parent[son] != root){
            int tmp = parent[son];
            parent[tmp] = root;
            son = tmp;
        }

        return root;
    }

    void _union(int a,int b){
        parent[find_parent(a)] = find_parent(b);
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        parent.resize(accounts.size());
        for(int i=0;i<accounts.size();++i) parent[i] = i;
        unordered_map<string,int> str_int; //索引parent
        unordered_map<int,set<string>> email;
        unordered_map<int,string> int_str;
        for(int i =0;i<accounts.size();++i){
            int_str[i] = accounts[i][0];
            for(int j=1;j<accounts[i].size();++j){
                if(str_int.count(accounts[i][j])) _union(i,str_int[accounts[i][j]]);
                str_int[accounts[i][j]] = i;
            }
        }

        for(int i=0;i<accounts.size();++i){
            email[find_parent(i)].insert(accounts[i].begin()+1,accounts[i].end());
        }

        vector<vector<string>> res;
        for(auto iter = email.begin();iter != email.end();++iter){
            vector<string> line;
            line.push_back(int_str[iter->first]);
            for(auto s_iter = iter->second.begin();s_iter != iter->second.end();++s_iter){
                line.push_back(*s_iter);
            }
            res.push_back(line);
        }

        return res;
    }
};


class Solution_findMedianSortedArrays {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        size_t sum = nums1.size() + nums2.size();
        if((sum & 0x1) == 0) return (find_kth(nums1,nums2,0,0,sum / 2)
                                     + find_kth(nums1,nums2,0,0,sum/2 + 1))/2;
        else return find_kth(nums1,nums2,0,0,sum/2 + 1);
    }


    double find_kth(const std::vector<int>& nums1,const std::vector<int>& nums2,
                    size_t A_idx,size_t B_idx,int k){
        if(nums1.size() == A_idx) return nums2[B_idx + k -1];
        if(nums2.size() == B_idx) return nums1[A_idx + k -1];
        if(k == 1) return std::min(nums1[A_idx],nums2[B_idx]);

        size_t mid = k/2-1;
        int A_key = (A_idx + mid) >= nums1.size() ? INT_MAX : nums1[A_idx + mid];
        int B_key = (B_idx + mid) >= nums2.size() ? INT_MAX : nums2[B_idx + mid];

        int new_k = k - k/2;
        if(A_key < B_key) return find_kth(nums1,nums2,A_idx + k / 2,B_idx,new_k);
        else return find_kth(nums1,nums2,A_idx,B_idx + k / 2,new_k);

    }
};

/*
class Solution_33 {
public:
    int search(std::vector<int>& nums, int target) {
        if(nums.size() == 0)return -1;
        if(nums.size() == 1) return (nums[0] == target) ? 0:-1;
        if(nums[0] < nums[nums.size()- 1])
            return binary_search(nums,0,nums.size()-1,target);

        int left = 0,right = nums.size(),mid,min_idx;
        while(left < right){
            if(left + 1 == right) min_idx = nums[left] < nums[right] ? left:right;
            mid = (left + right) / 2;
            if(nums[mid] > nums[left]) left = mid;
            else right = mid;
        }

        int res = binary_search(nums,0,min_idx-1,target);
        if(res != -1) return res;
        return binary_search(nums,min_idx,nums.size()-1,target);

    }


    int binary_search(std::vector<int> &nums,int left,int right,int target){
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) left = mid + 1;
            else right = mid -1;
        }
        return -1;
    }


};
*/
class Solution_1143 {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        if(text1.size()==0 || text2.size()==0) return 0;
        std::vector<std::vector<int>> dp;
        std::vector<int> tmp(text2.size());
        for(int i=0;i<text1.size();++i) dp.push_back(tmp);

        for(int i=0;i<text1.size();++i){
            for(int j=0;j<text2.size();++j){
                if(text1[i]==text2[j]){
                    dp[i][j] = (((i-1) >=0 && (j-1)>=0) ? dp[i-1][j-1] : 0) + 1;
                }else{
                    dp[i][j] = std::max(((i-1) >=0 ? dp[i-1][j]:0),((j-1>=0)?dp[i][j-1]:0));
                }
            }
        }

        return dp[text1.size()-1][text2.size()-1];
    }
};

class Solution_1312 {
public:
    int minInsertions(std::string s) {
//        std::vector<std::vector<int>> dp;
//        for(int i=0;i<s.size();++i) {
//            std::vector<int> tmp(s.size());
//            dp.push_back(tmp);
//        }
        int dp[s.size()][s.size()];
        memset(dp,0,sizeof(dp));
        for(int gap=1;gap<s.size();++gap){
            for(int low = 0,high = low + gap;high< s.size();++low,++high){
                if(s[low] == s[high]) dp[low][high] = dp[low+1][high-1];
                else dp[low][high] = 1 + std::min(dp[low+1][high], dp[low][high-1]);
            }
        }
        return dp[0][s.size()-1];
    }
};

class Solution_151 {
public:
    std::string reverseWords(std::string s) {
        std::string res;
        if(s.size() == 0) return res;

        std::string tmp;
        for(size_t idx = 0;idx < s.size();++idx){
            if(s[idx] == ' '){
                if(tmp.size()){
                    reverse(tmp.begin(),tmp.end());
                    res += tmp;
                    res += ' ';
                    tmp.clear();
                }
            }else tmp+=s[idx];
        }

        if(tmp.size()){
            reverse(tmp.begin(),tmp.end());
            res+=tmp;
            res += ' ';
        }

        reverse(res.begin(),res.end()-1);
        res.erase(res.end()-1);
        return res;
    }
};

class Solution_8 {
public:
    int myAtoi(std::string str) {
        if(str.size() == 0) return 0;
        long long int res = 0;
        bool negate = false;
        int idx = 0;

        while(str[idx] == ' ')++idx;
        if(str[idx] == '-'){
            negate = true;
            ++idx;
        }
        if(!negate && str[idx] == '+')++idx;

        while('0'<=str[idx] && str[idx] <='9'){
            res = res*10 + str[idx]-'0';
            if(negate && -res <= INT_MIN) return INT_MIN;
            if(!negate && res >=INT_MAX) return INT_MAX;
            ++idx;
        }

        res = negate ? -res : res;
        return res;
    }
};


class Solution_43 {
public:
    std::string multiply(std::string num1, std::string num2) {
        std::string res;
        if(num1.size()==0 || num2.size()==0) return res;
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());

        std::vector<int> n1(num1.size()),n2(num2.size());
        std::vector<int> n_res;
        for(int i=0;i<num1.size();++i) n1[i] = num1[i] - '0';
        for(int i=0;i<num2.size();++i) n2[i] = num2[i] - '0';

        for(int i=0;i<n1.size();++i){

            int carry = 0;
            std::vector<int> tmp(i,0);
            for(int j=0;j<n2.size();++j){
                int mul = n1[i] * n2[j] + carry;
                tmp.push_back(mul % 10);
                carry = mul / 10;
            }
            //reverse(tmp.begin(),tmp.end());
            if(carry)tmp.push_back(carry);
            add_sign(n_res,tmp);
        }

        bool flag = false;
        for(int i=n_res.size()-1;i>=0;--i){
            if(n_res[i] != 0) flag = true;
            if(flag || i==0)res += (n_res[i] + '0');
        }
        return res;
    }


    void add_sign(std::vector<int> &res,const std::vector<int>& num){
        int i=0,j=0,carry = 0;
        while(i < res.size() && j < num.size()){
            int sum = res[i] + num[j] + carry;
            res[i] = sum % 10;
            carry = sum / 10;
            ++i,++j;
        }

        while(j < num.size()){
            int sum = num[j] + carry;
            res.push_back(sum % 10);
            carry = sum / 10;
            ++j;
        }
        if(carry)res.push_back(carry);
    }
};


class Solution_204 {
public:
    int countPrimes(int n) {
        std::vector<bool> prime(n + 1,true);
        int num = 0;
        for(int i=2;i<n;++i){
            if(prime[i] == true){
                ++num;
                for(int j = i;j<=n;j+=i)prime[j] = false;
            }
        }
        return num;
    }
};


class Solution_46 {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> tmp;
        dfs(nums,0,res,tmp);
        return res;
    }

    void dfs(std::vector<int> &nums,int idx,std::vector<std::vector<int>> &res,std::vector<int> & tmp){
        if(idx >= nums.size()){
            res.push_back(tmp);
            return;
        }

        for(int i=idx;i < nums.size();++i){
            std::swap(nums[idx],nums[i]);
            tmp.push_back(nums[idx]);
            dfs(nums,idx+1,res,tmp);
            tmp.pop_back();
            std::swap(nums[idx],nums[i]);
        }
    }
};

class Solution_474 {
public:
    int findMaxForm(std::vector<std::string>& strs, int m, int n) {
        int _max = 0;
        for(int i=0;i<strs.size()-1;++i){
            std::vector<int> hash(2);
            for(auto val : strs){
                for(auto ch :val) hash[ch - '0'] +=1;
                if(hash[0] <= m && hash[1] <= n && val.size() > _max) _max = val.size();
            }
        }

        return _max;
    }
};

class Solution_39 {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>>  res;
        sort(candidates.begin(),candidates.end());
        std::vector<int> tmp;
        dfs(candidates,0,0,target,res,tmp);
        return res;

    }

    void dfs(const std::vector<int>& candidates,int idx,int cur,int target,
             std::vector<std::vector<int>> & res,std::vector<int> &tmp){

        if(target == cur){
            res.push_back(tmp);
            return;
        }
        if(idx >= candidates.size() || cur > target) return;

        int num = (target - cur)/candidates[idx];
        for(int i=0,sum = 0;i<num;++i){
            tmp.push_back(candidates[idx]);
            sum += candidates[idx];
            dfs(candidates,idx+1,cur+sum,target,res,tmp);
        }

        for(int i=0;i<num;++i)tmp.pop_back();
        dfs(candidates,idx+1,cur,target,res,tmp);
    }
};

class Solution_1160 {
public:
    int countCharacters(std::vector<std::string>& words, std::string chars) {
        std::vector<int> hash(260);
        for(auto val : chars) hash[val] += 1;

        int sum =0;
        for(auto word : words){
            std::unordered_map<char,int> map;
            for(auto ch :word) {
                if(map.find(ch) == map.end()) map[ch] = 1;
                else map[ch] += 1;
            }
            bool res = true;
            for(auto iter = map.begin();iter != map.end();++iter){
                if(hash[iter->first] < iter->second){
                    res = false;
                    break;
                }
            }
            if(res) sum += word.size();
        }

        return sum;
    }
};

class Solution_15_a {
public:
    vector<vector<int>> twoSum(vector<int>& nums,int start, int target) {
        int left = start,right = nums.size()-1;
        vector<vector<int>> res;
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum < target)++left;
            else if(sum > target) --right;
            else{
                res.push_back(vector<int>{nums[left],nums[right]});
                --right;
                ++left;
                while(right > left && nums[right] == nums[right+1])--right;
                while(right > left && nums[left] == nums[left-1])++left;
            }
        }
        return res;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int start = 0,end = nums.size()-1;
        while(start + 2 <= end){
            vector<vector<int>> two = twoSum(nums,start+1,0-nums[start]);
            for(int j=0;j<two.size();++j){
                two[j].insert(two[j].begin(),nums[start]);
                res.push_back(two[j]);
            }
            while(++start < end && nums[start]==nums[start-1]);
        }
        return res;
    }
};
class Solution15 {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        int left = 0,mid = 1,right = nums.size()-1;
        std::vector<std::vector<int>> res;
        sort(nums.begin(),nums.end());
        while(left < nums.size() - 2){
            if(left > 0)while(left < nums.size() && nums[left] == nums[left-1])++left;
            mid = left + 1;
            right = nums.size()-1;
            while(mid < right){
                int sum = nums[left] + nums[mid] + nums[right];
                if(sum > 0){
                    --right;
                    while(right > mid && nums[right] == nums[right+1])--right;
                }
                else if(sum < 0){
                    ++mid;
                    while(mid < right && nums[mid] == nums[mid-1])++mid;
                }else{
                    std::vector<int> sum;
                    sum.push_back(nums[left]);
                    sum.push_back(nums[mid]);
                    sum.push_back(nums[right]);
                    res.push_back(sum);
                    ++mid;
                    --right;
                    while(right > mid && nums[right] == nums[right+1])--right;
                    while(mid < right && nums[mid] == nums[mid-1])++mid;
                }
            }
            ++left;
        }
        return res;
    }
};

class Solution1 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int,int> map;
        std::vector<int> res;

        for(int i=0;i<nums.size();++i){
            auto iter = map.find(target-nums[i]);
            if(iter != map.end()){
                res.push_back(iter->second);
                res.push_back(i);
                return res;
            }
            map[nums[i]] = i;
        }
        return res;

    }
};


class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if((count & 0x1)  == 0){
            min_heap.push(num);
            max_heap.push(min_heap.top());
            min_heap.pop();
        }else{
            max_heap.push(num);
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        ++count;
    }

    double findMedian() {
        //if(count == 0) return 0;
        if((count & 0x1) == 1) return max_heap.top();
        else return ((double)max_heap.top() + min_heap.top())/2;
    }

    std::priority_queue<int> max_heap;
    std::priority_queue<int,std::vector<int>,std::greater<int>> min_heap;
    int count = 0;
};


class Solution48 {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        for(size_t i=0;i<matrix.size()/2;++i){
            //swap(matrix[i],matrix[matrix.size()-i-1]);
            matrix[i].swap(matrix[matrix.size()-i-1]);
        }

        for(size_t i=0;i<matrix.size();++i){
            for(size_t j=i;j<matrix[0].size();++j){
                if(i != j){
                    std::swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
    }
};

#endif //C___LEETCODE_EN_H
