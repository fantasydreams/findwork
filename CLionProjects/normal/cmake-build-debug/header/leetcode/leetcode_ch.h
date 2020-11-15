//
// Created by sharwen on 2020/3/15.
//

#ifndef C___LEETCODE_CH_H
#define C___LEETCODE_CH_H
#include "../type.h"

//887. 鸡蛋掉落
class Solution {
    int dp(int K, int N){
        if(K == 1) return N;
        if(N == 0) return 0;
        static map<pair<int,int>,int> memo;

        if(memo.find(make_pair(K,N)) != memo.end()) return memo[make_pair(K,N)];
        else{
            int res = INT_MAX;
            // for(int i=1; i<= N;++i){
            //     res = min(res, max(dp(K,N-i),dp(K-1,i-1)) + 1);
            // }
            int low = 1, high = N;
            while(low <= high){
                int mid = low + (high - low) / 2;
                int broken = dp(K-1, mid-1);
                int noBroken = dp(K, N - mid);
                if (broken > noBroken){
                    res = min(res, broken + 1);
                    high = mid - 1;
                }else{
                    res = min(res, noBroken + 1);
                    low = mid + 1;
                }
            }
            memo[make_pair(K,N)] = res;
            return res;
        }
    }
public:
    int superEggDrop(int K, int N) {
        return dp(K,N);
    }
};

//72. 编辑距离
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int> (word2.size() + 1, 0));
        for(int i=0;i<=word1.size();++i){
            dp[i][0] = i;
        }

        for(int i=0;i<=word2.size();++i){
            dp[0][i] = i;
        }

        for(int i=1;i<= word1.size();++i){
            for(int j=1;j<=word2.size();++j){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                }
            }
        }

        return dp[word1.size()][word2.size()];
    }
};


// 300. 最长上升子序列
class Solution_300_1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for(int i=0;i<nums.size();++i){
            int left = 0, right = dp.size();
            while(left < right){
                int mid=left + (right - left) / 2;
                if(dp[mid] < nums[i]) left = mid + 1;
                else right = mid;
            }

            if(left == dp.size()){
                dp.push_back(nums[i]);
            }else{
                dp[left] = nums[i];
            }
        }
        return dp.size();
    }
};

class Solution_300_2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res = 0;
        for(int i = 0;i < nums.size();++i){
            int _max = 1;
            for(int j = 0;j < i;++j){
                if(nums[i] > nums[j]){
                    _max = max(_max, dp[j] + 1);
                }
            }
            dp[i] = _max;
            res = max(res, _max);
        }

        return res;
    }
};

class Solution_ch_18 {
    vector<vector<int>> twoSum(vector<int>& nums, int start, int target){
        int end = nums.size() - 1;
        vector<vector<int>> res;
        while(start < end){
            int sum = nums[start] + nums[end];
            if(sum < target) ++start;
            else if(sum > target) --end;
            else{
                res.push_back(vector<int>{nums[start],nums[end]});
                while(++start < end && nums[start] == nums[start-1]);
                while(--end > start && nums[end] == nums[end+1]);
            }
        }
        return res;
    }

    vector<vector<int>> threeSum(vector<int> &nums, int start, int target){
        vector<vector<int>> res;
        int end = nums.size();
        while(start + 1 < end){
            vector<vector<int>> two = twoSum(nums,start + 1,target-nums[start]);
            for(int j = 0;j < two.size();++j){
                two[j].insert(two[j].begin(),nums[start]);
                res.push_back(two[j]);
            }
            while(++start < nums.size() && nums[start] == nums[start-1]);

        }

        return res;
    }
public:

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int start = 0,end = nums.size();
        while(start < end){
            vector<vector<int>> three = threeSum(nums,start + 1,target-nums[start]);
            for(int j = 0;j < three.size();++j){
                three[j].insert(three[j].begin(),nums[start]);
                res.push_back(three[j]);
            }
            while(++start < nums.size() && nums[start] == nums[start-1]);

        }

        return res;
    }
};

class Solution_ch_15 {
    void getSum_pack(vector<int>& nums, int idx, int cur, int const target, vector<int> & vec, set<vector<int>> &res){
        if(cur == target && vec.size() == 3){
            vector<int> tmp = vec = vec;
            sort(tmp.begin(),tmp.end());
            res.insert(tmp);
        }
        for(int i = idx;i<nums.size(); ++i){
            vec.push_back(nums[i]);
            getSum_pack(nums,i+1,cur + nums[i],target, vec, res);
            vec.pop_back();
        }
    }
    void getSum_three_indicator(vector<int> &nums, vector<vector<int>> &res, int target){
        if(nums.size() < 3) return;
        sort(nums.begin(),nums.end());
        int left = 0, right = nums.size();
        bool is_ans = false;
        set<vector<int>> tmp;
        for(int i = 0;i < nums.size() - 2; ++i){
            if(is_ans){
                while(i < nums.size() - 2 && nums[i] == nums[i-1]){
                    ++i;
                }
                is_ans = false;
            }
            int start = i + 1, end = nums.size() - 1;
            while(start < end){
                int sum = nums[i] + nums[start] + nums[end];
                if(sum == target){
                    is_ans = true;
                    vector<int> vec;
                    vec.push_back(nums[i]);
                    vec.push_back(nums[start]);
                    vec.push_back(nums[end]);
                    tmp.insert(vec);
                    if(nums[start] == nums[end])break;
                    ++start;--end;
                }else if(sum < target) ++start;
                else --end;
            }
        }

        for(auto it = tmp.begin(); it != tmp.end(); ++it){
            res.push_back(*it);
        }

    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // set<vector<int>> tmp;
        // vector<int> vec;
        // getSum_pack(nums,0,0,0,vec,tmp);
        // vector<vector<int>> res;
        // for(auto it = tmp.begin();it != tmp.end(); ++it){
        //     res.push_back(*it);
        // }
        vector<vector<int>> res;
        if(nums.size() == 0) return res;
        getSum_three_indicator(nums,res,0);

        return res;
    }
};

//二叉树遍历 236. 二叉树的最近公共祖先
class Solution236 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root == p || root ==q) return root;
        TreeNode * left = lowestCommonAncestor(root->left,p,q);
        TreeNode * right= lowestCommonAncestor(root->right,p,q);
        if(left && right) return root;
        if(!left && ! right) return nullptr;
        return left ? left:right;
    }
};

//dp 337. 打家劫舍 III
class Solution337{
    void dfs(TreeNode * root){
        if(!root) return;
        dfs(root->left);
        dfs(root->right);
        f[root] = root->val + g[root->left] + g[root->right];
        g[root] = max(f[root->left], g[root->left]) + max(f[root->right],g[root->right]);
    }
    unordered_map<TreeNode *,int> f,g;
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return max(f[root],g[root]);
    }
};

//dp 213. 打家劫舍 II
class Solution213 {
public:
    int rob_real(vector<int>& nums) {
        if(nums.size()== 0)return 0;
        if(nums.size()== 1)return nums[0];
        int dp_i, dp_i_2 = nums[0],dp_i_1 = max(dp_i_2,nums[1]);
        
        for(int i=2;i<nums.size();++i){
            dp_i = max(dp_i_2 + nums[i], dp_i_1);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }

        return dp_i_1;
    }

    int rob(vector<int>& nums){
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        
        vector<int> left(nums.begin(),nums.end()-1);
        vector<int> right(nums.begin() + 1,nums.end());
        return max(rob_real(left),rob_real(right));
    }
};


//dp背包 198. 打家劫舍

class Solution198_b {
public:

    int rob(vector<int>& nums) {
        if(nums.size()== 0)return 0;
        if(nums.size()== 1)return nums[0];
        int dp_i, dp_i_2 = nums[0],dp_i_1 = max(dp_i_2,nums[1]);
        
        for(int i=2;i<nums.size();++i){
            dp_i = max(dp_i_2 + nums[i], dp_i_1);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }

        return dp_i_1;
    }
};
class Solution198_dp_a {
public:

    int rob(vector<int>& nums) {
        if(nums.size()== 0)return 0;
        if(nums.size()== 1)return nums[0];
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        dp[1] = max(dp[0],nums[1]);
        for(int i=2;i<nums.size();++i){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }

        return dp[nums.size()-1];
    }
};

// 198. 打家劫舍 递归
class Solution198_reverse {
public:
    void find_max(vector<int> &nums, int idx, int cur, int & max){
        if(idx >= nums.size()){
            if(max < cur){
                max = cur;
            }
            return;
        }
        for(int i = idx;i < nums.size();++i){
            find_max(nums,i + 2, cur + nums[i], max);
            find_max(nums,i + 1, cur, max);
        }
    }
    int rob(vector<int>& nums) {
        int _max = 0;
        find_max(nums,0,0,_max);
        return _max;
    }
};

// dp 714. 买卖股票的最佳时机含手续费
class Solution714 {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // dp[i][0] = max(dp[i][0],dp[i][1] + prices[i]);
        // dp[i][1] = max(dp[i][1],dp[i-1][1] - prices[i]);
        int dp_0 = 0,dp_1=INT_MIN,dp_0_pre = 0;
        for(int i=0;i<prices.size();++i){
            dp_0_pre = dp_0;
            dp_0 = max(dp_0,dp_1 + prices[i]);
            dp_1 = max(dp_1,dp_0_pre - prices[i]-fee);
        }
        return dp_0;
    }
};

//dp 309. 最佳买卖股票时机含冷冻期
class Solution309 {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][0] = max(dp[i][0],dp[i][1] + prices[i]);
        // dp[i][1] = max(dp[i][1],dp[i][0]_pre_pre - prices[i]);

        int dp_0 = 0,dp_1 = INT_MIN, dp_0_pre = 0,dp_0_pre_pre = 0;
        for(int i=0;i<prices.size();++i){
            dp_0_pre_pre = dp_0_pre;
            dp_0_pre = dp_0;
            dp_0 = max(dp_0, dp_1+prices[i]);
            dp_1 = max(dp_1, dp_0_pre_pre - prices[i]);
        }
        return dp_0;
    }
};

// dp 188. 买卖股票的最佳时机 IV
class Solution188 {
public:
    int maxProfit(vector<int>& prices) {
        int dp_0 = 0, dp_1 = INT_MIN;
        for(int i=0;i<prices.size();++i){
            int dp_0_re= dp_0;
            dp_0 = max(dp_0, dp_1 + prices[i]);
            dp_1 = max(dp_1, dp_0_re-prices[i]);
        }
        return dp_0;
    }

    int maxProfit(int k, vector<int>& prices) {
        //dp[i][k][0] = max(dp[i-1][k][0],dp[i-1][k][1] + prices[i]);
        //dp[i][k][1] = max(dp[i-1][k][1],dp[i-1][k-1][0] - prices[i]);

        if(k > prices.size() / 2){
            return maxProfit(prices);
        }

        vector<vector<int>>  dp;
        for(int i=0;i<=k;++i){
            vector<int> line;
            line.push_back(0);
            line.push_back(INT_MIN);
            dp.push_back(line);

        }

        for(int i=0;i<prices.size();++i){
            for(int j = k;j>=1;--j){
                dp[j][0] = max(dp[j][0],dp[j][1]+prices[i]);
                dp[j][1] = max(dp[j][1],dp[j-1][0]-prices[i]);
            }
        }

        return dp[k][0];
    }
};


//dp  123. 买卖股票的最佳时机 III
class Solution123 {
public:
    int maxProfit(vector<int>& prices) {
        //dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + price[i]);
        //dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - price[i]);

        //dp[i][0][0] = 0,
        //dp[i][0][1] = INT_MIN;
        //dp[-1][0][0] = dp[-1][1][0] = dp[-1][2][0] = 0;
        //dp[-1][0][1] = dp[-1][1][1] = dp[-1][2][1] = INT_MIN; the app
        //dp[i][1][0] = max(dp[i-1][1][0],dp[i-1][1][1] + price[i]);
        //dp[i][1][1] = max(dp[i-1][1][1],- price[i]);
        //dp[i][2][0] = max(dp[i-1][2][0],dp[i-1][2][1] + prices[i]);
        //dp[i][2][1] = max(dp[i-1][2][1],dp[i-1][1][0] - prices[i]);

        int dp_10  = 0,dp_11=-prices[0], dp_20 = 0, dp_21 = -prices[0];
        for(int i=1;i<prices.size();++i){
            dp_20 = max(dp_20,dp_21 + prices[i]);
            dp_21 = max(dp_21,dp_10 - prices[i]);
            dp_10 = max(dp_10,dp_11 + prices[i]);
            dp_11 = max(dp_11,-prices[i]);
        }

        return dp_20;
    }
};


// dp 122. 买卖股票的最佳时机
/*
 * 状态转移方程
 * base case：
    dp[-1][k][0] = dp[i][0][0] = 0
    dp[-1][k][1] = dp[i][0][1] = -infinity

    状态转移方程：
    dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
    dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])

    买股票的特例，无穷次，可看作k=k-1
 */

class Solution122 {
public:
    int maxProfit(vector<int>& prices) {
        int dp_0 = 0, dp_1 = INT_MIN;
        for(int i=0;i<prices.size();++i){
            int dp_0_re= dp_0;
            dp_0 = max(dp_0, dp_1 + prices[i]);
            dp_1 = max(dp_1, dp_0_re-prices[i]);
        }
        return dp_0;
    }
};


// dp 121. 买卖股票的最佳时机
/*
 * 状态转移方程
 * base case：
    dp[-1][k][0] = dp[i][0][0] = 0
    dp[-1][k][1] = dp[i][0][1] = -infinity

    状态转移方程：
    dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
    dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])

    买股票的特例，一次
 */

class Solution121 {
public:
    int maxProfit(vector<int>& prices) {
        int dp_0 = 0, dp_1 = INT_MIN;
        for(int i=0;i<prices.size();++i){
            dp_0 = max(dp_0, dp_1 + prices[i]);
            dp_1 = max(dp_1, -prices[i]);
        }
        return dp_0;
    }
};

//滑动窗口 3. 无重复字符的最长子串
class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[128] = {0};
        int left = 0,right = 0; //[left,right);
        int maxLen = 0;
        while(right < s.size()){
            if(hash[s[right]] == 0){
                ++hash[s[right++]];
            }else{
                if(maxLen < right - left){
                    maxLen = right - left;
                }
                --hash[s[left++]];
            }
        }

        if(maxLen < right - left){
            maxLen = right - left;
        }

        return maxLen;
    }
};

// 滑动窗口 438. 找到字符串中所有字母异位词
class Solution438 {
public:
    vector<int> findAnagrams(string s, string p) {
        int winFreq[128] = {0}, tFreq[128] = {0};
        int dis = 0,diff = 0;
        int left = 0,right = 0;

        for(int i=0;i<p.size();++i){
            tFreq[p[i]]+=1;
        }

        vector<int> res;
        while(right < s.size()){
            if(dis < p.size()){
                ++winFreq[s[right]];
                if(winFreq[s[right]] <= tFreq[s[right]]){
                    ++dis;
                }else{
                    ++diff;
                }
                ++right;
            }

            while(dis == p.size()){
                if(diff == 0){
                    res.push_back(left);
                }

                if(winFreq[s[left]] <= tFreq[s[left]]){
                    --dis;
                }else{
                    --diff;
                }
                --winFreq[s[left]];
                ++left;
            }
        }

        return res;
    }
};

//滑动窗口 567. 字符串的排列


//"a i n w k c k i f y k  x  l  r  i  b  a  y  p  k"
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
class Solution576 {
public:
    bool checkInclusion(string s1, string s2) {
        int winFreq[128] = {0}, tFreq[128] = {0};
        int distance = 0,diffDis = 0;
        int left = 0,right = 0;//[left,right);

        for(int i=0;i<s1.size();++i){
            ++tFreq[s1[i]];
        }

        while(right < s2.size()){
            if(distance < s1.size()){
                ++winFreq[s2[right]];
                if(winFreq[s2[right]] <= tFreq[s2[right]]){
                    ++distance;
                }else{
                    ++diffDis;
                }
                ++right;
            }

            while(distance == s1.size()){
                if(diffDis == 0) return true;
                if(winFreq[s2[left]] > tFreq[s2[left]]){
                    --diffDis;
                }else{
                    --distance;
                }
                --winFreq[s2[left++]];
            }
        }

        return false;
    }
};

//滑动窗口，76. 最小覆盖子串
class Solution76 {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        int winFreq[128] = {0};
        int tFreq[128] = {0};
        int distance = 0;
        int minLen = INT_MAX;
        int begin = 0;

        for(int i=0;i<t.size();++i){
            ++tFreq[t[i]];
        }

        int left = 0,right = 0;//[left,right)
        while(right < s.size()){
            if(distance < t.size()){
                ++winFreq[s[right]];
                if(winFreq[s[right]] <= tFreq[s[right]]){
                    ++distance;
                }
                ++right;
            }

            while(distance == t.size()){
                if(winFreq[s[left]] > tFreq[s[left]]){
                    --winFreq[s[left++]];
                    continue;
                }

                if(right-left < minLen) {
                    minLen = right-left;
                    begin = left;
                }
                --distance;
                --winFreq[s[left++]];
            }
        }

        if(minLen == INT_MAX) return "";
        return s.substr(begin, minLen);
    }
};

class Solution_offer36_a {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        Node * pre = nullptr;
        convert2list(root,pre);
        while(root->left)root=root->left;
        root->left = pre;
        pre->right = root;
        return root;
    }

    void convert2list(Node *root, Node * &pre){
        stack<Node *> st;
        push_left_util_null(root,st);
        while(!st.empty()){
            Node * node = st.top();st.pop();
            if(pre)pre->right = node;
            node->left = pre;
            pre = node;
            node = node->right;
            push_left_util_null(node,st);
        }
    }

    void push_left_util_null(Node * root,stack<Node *> &st){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
};

class Solution_offer36 {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        Node * pre = nullptr;
        convert2list(root,pre);
        while(root->left)root=root->left;
        root->left = pre;
        pre->right = root;
        return root;
    }

    void convert2list(Node *root, Node * &pre){
        if(!root)return;
        convert2list(root->left,pre);
        if(pre)pre->right = root;
        root->left = pre;
        pre = root;
        convert2list(root->right,pre);
    }
};

class Solution59_2 {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        for(int i=0;i<n;++i){
            vector<int> line(n);
            res.push_back(line);
        }

        int _max = n * n,_cur = 1;
        int left = 0,right = n-1,top=0,bottom = n-1;
        while(left <= right && top <= bottom){

            for(int i=left;i<=right && top <= bottom;++i)res[top][i] = _cur++;
            ++top;

            for(int i=top;i<=bottom && left <= right;++i)res[i][right]=_cur++;
            --right;

            for(int i=right;i>=left && top <= bottom;--i) res[bottom][i] = _cur++;
            --bottom;

            for(int i=bottom;i>=top && left <= right;--i) res[i][left] = _cur++;
            ++left;
        }

        return res;
    }
};

#endif //C___LEETCODE_CH_H
