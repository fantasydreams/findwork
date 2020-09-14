//
// Created by sharwen on 2020/3/15.
//

#ifndef C___LEETCODE_CH_H
#define C___LEETCODE_CH_H
#include "../type.h"

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
