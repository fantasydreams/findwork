//
// Created by Sharwen on 2020/2/24.
//

#ifndef C___AFTER_26_H
#define C___AFTER_26_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <queue>
#include <string>

class Solution_offer44 {
public:
    int findNthDigit(int n) {
        if(n < 9) return n;
        int base = 1;
        int number = n-1;

        long int bits = 9;
        while(number >= bits){
            number -= bits;
            bits = pow(10,base+1)*9 * base;
            ++base;
        }

        int num = pow(10,base-1) + number / base;

        std::string bit = std::to_string(num);
        return bit[number % base] - '0';
    }
};

class Solution_offer48 {
public:
    int lengthOfLongestSubstring(std::string s) {
        if(s.size() == 0) return 0;
        std::vector<int> hash(260);

        int left = 0,right = 0,max_len = 0,count = 0;
        for(int i=0;i<s.size();++i){
            if(++hash[s[i]] > 1)++count;
            else{
                right = i;
                max_len = std::max(max_len,right-left+1);
            }
            while(count){
                if(--hash[s[left]] == 1)--count;
                ++left;
            }

        }
        return max_len;
    }
};

class Solution_offer46 {
public:
    int translateNum(int num) {
        std::string str = std::to_string(num);
        std::vector<int> dp(str.size() + 1);
        dp[0] = 1;dp[1]=1;
        for(int i=1;i<str.size();++i){
            if((str[i-1]-'0' ) * 10 + str[i] - '0' <= 25 && (str[i-1]-'0' )!=0){
                dp[i+1] = dp[i-1]+dp[i];
            }else dp[i+1] = dp[i];
        }
        return dp[str.size()];
    }
};

class Solution_offer47 {
public:
    int maxValue(std::vector<std::vector<int>>& grid) {
        if(grid.size() ==0) return 0;
        /*
        int _max = 0;
        dfs(grid,0,0,grid.size(),grid[0].size(),_max,0);
        */
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                int up = i-1 <0 ? 0:grid[i-1][j];
                int left = j - 1 < 0?0:grid[i][j-1];
                grid[i][j] += std::max(up,left);
            }
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }



    void dfs(std::vector<std::vector<int>>& grid,int i,int j,int line,int col,int&_max,int cur){
        if(i >=line || j >= col) return;
        if(i == line-1 && j ==col -1 && _max < cur + grid[i][j]){
            _max = cur + grid[i][j];
        }
        dfs(grid,i,j+1,line,col,_max,cur+grid[i][j]);
        dfs(grid,i+1,j,line,col,_max,cur+grid[i][j]);
    }
};


struct listNode {
    int val;
    listNode *next;
    listNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class MedianFinder_offer41 {
public:
    /** initialize your data structure here. */
    MedianFinder_offer41() {

    }

    void addNum(int num) {
        if((count & 0x1) == 0){
            max_heap.push(num);
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else{
            min_heap.push(num);
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        ++count;
    }

    double findMedian() {
        if((count &0x1) == 0){
            int left = max_heap.top();
            int right = min_heap.top();
            return (double)(left + right) / 2;
        }
        else return min_heap.top();
    }

    std::priority_queue<int,std::vector<int>,std::less<int> > max_heap;
    std::priority_queue<int,std::vector<int>,std::greater<int> > min_heap;
    int count = 0;
};

class Solution_offer_2 {
public:
    int cuttingRope(int n) {
        if(n == 1) return 1;
        if(n == 2) return 1;
        if(n == 3) return 2;

        long int left = n % 3,res = 1;
        for(int i=1;i<n/3;++i){
            res = res * 3 % 1000000007;
        }

        if(left == 0) res = res * 3 % 1000000007;
        if(left == 1) res = res * 4 % 1000000007;
        if(left == 2) res = res * 6 % 1000000007;

        return res;
    }
};

class Solution_offer14_1 {
public:
    int cuttingRope(int n) {
        if(n == 1) return 1;
        if(n == 2) return 1;
        if(n == 3) return 2;

        int left = n % 3;
        int res = pow(3,n/3);

        if(left == 1){
            res = res / 3 * 4;
        }
        else if(left == 2){
            res *= 2;
        }

        return res;
    }
};

class Solution_offer13 {
public:
    int movingCount(int m, int n, int k) {
        int count =0;
        memset(visited,0,sizeof(visited));
        dfs(0,0,m,n,k,count);
        return count;
    }

    void dfs(int i,int j,int m,int n,int k,int &count){
        if(i< 0 || j < 0 || i>=m || j >=n ||
           (i/10 + i % 10 + j /10 + j % 10) > k || visited[i][j])return;
        ++count;
        visited[i][j] = 1;
        dfs(i-1,j,m,n,k,count);
        dfs(i+1,j,m,n,k,count);
        dfs(i,j-1,m,n,k,count);
        dfs(i,j+1,m,n,k,count);
    }
    bool visited[110][110];
};

class Solution_offer66 {
public:
    std::vector<int> constructArr(std::vector<int>& a) {
        std::vector<int> res(a.size());
        get_res(res);
        return res;
    }

    void cacualte(std::vector<int>& a){
        l_r[0] = 1;
        for(int i=1;i<=a.size();++i){
            l_r[i] = l_r[i-1] * a[i-1];
        }

        r_l[a.size()] = 1;
        for(int i=a.size()-1;i>=0;--i){
            r_l[i] = r_l[i+1] * a[i];
        }
    }

    void get_res(std::vector<int> & res){
        for(int i=0;i<res.size();++i){
            res[i] = l_r[i] * r_l[i+1];
        }
    }

private:
    int l_r[100010],r_l[100010];
};

class MaxQueue_offer59_2 {
public:
    MaxQueue_offer59_2() {

    }

    int max_value() {
        if(que.size() == 0)return -1;
        else return Max.front();
    }

    void push_back(int value) {
        que.push(value);
        while(Max.size() && Max.back() < value){
            Max.pop_back();
        }
        Max.push_back(value);
    }

    int pop_front() {
        if(que.size() == 0)return -1;
        if(Max.front() == que.front())Max.pop_front();

        int res = que.front();
        que.pop();
        return res;

    }
private:
    std::queue<int> que;
    std::deque<int> Max;

};


class Solution_offer28 {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        return mirror(root->left,root->right);
    }

    bool mirror(TreeNode* l_r,TreeNode*r_r){
        if(!l_r && !r_r){
            return true;
        }
        if((!l_r && r_r) || (l_r && !r_r)){
            return false;
        }

        return (l_r->val == r_r->val) && mirror(l_r->left,r_r->right)
               && mirror(l_r->right,r_r->left);
    }
};

class Solution_offer27 {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A || !B){
            return false;
        }

        return is_sub(A,B) || isSubStructure(A->left,B) || isSubStructure(A->right,B);

    }

    bool is_sub(TreeNode* A, TreeNode* B) {
        if(!B){
            return true;
        }

        if(!A){
            return false;
        }

        return (A->val == B->val) && is_sub(A->left,B->left) && is_sub(A->right,B->right);
    }
};

class Solution_offer25 {
public:
    listNode* mergeTwoLists(listNode* l1, listNode* l2) {
        listNode * head = new listNode(0);
        listNode * p = head;
        while(l1 && l2){
            if(l1->val < l2->val){
                p->next = l1;
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        p->next = l1 ? l2 : l2;

        listNode * res= head->next;
        delete head;
        return res;
    }
};

class Solution_offer22 {
public:
    listNode* getKthFromEnd(listNode* head, int k) {
        if(k <= 0){
            return nullptr;
        }

        listNode * before = head,*after = head;
        for(int step =1 ;step < k;++step){
            after = after->next;
            if(!after){
                return nullptr;
            }
        }

        while(after->next){
            before = before->next;
            after = after->next;
        }
        return before;
    }

    listNode * create_forward_list(const std::vector<int> & data){
        if(data.size() == 0) return nullptr;

        listNode * head = new listNode(data[0]);
        listNode * p = head;

        for(size_t idx = 1;idx < data.size(); ++idx){
            p->next = new listNode(data[idx]);
            p=p->next;
        }

        return head;
    }
};

class Solution_offer20 {
public:
    bool isNumber(std::string s) {
        auto start = s.find_first_not_of(" ");
        auto end = s.find_last_not_of(" ");
        if(end == std::string::npos){
            return false;
        }

        s = s.substr(start,end-start + 1);
        if(s.size() == 0){
            return false;
        }

        //找e
        auto e = s.find_first_of("eE");
        if(e == std::string::npos){
            return judge_base(s);
        }else{
            return judge_base(s.substr(0,e)) && judge_index(s.substr(e+1,s.size()));
        }



    }

    bool judge_base(std::string str){

        std::string base = str;
        if(base.size()== 0){
            return false;
        }

        if(base[0] == '+' || base[0] == '-'){
            base.erase(base.begin());
        }
        auto symbol = base.find_first_of("+-");
        if(symbol != std::string::npos){
            return false;
        }

        auto point = base.find_first_of(".");
        if(point != std::string::npos){
            base.erase(base.begin() + point);
            point = base.find_first_of(".");
            if(point != std::string::npos){
                return false;
            }
        }

        auto n_num = base.find_first_not_of("0123456789");
        if(n_num != std::string::npos || base.size() == 0){
            return false;
        }

        return true;
    }

    bool judge_index(std::string str){
        std::string index = str;
        if(index.size() == 0){
            return false;
        }

        if(index[0] == '+' || index[0] == '-'){
            index.erase(index.begin());
        }

        auto symbol = index.find_first_of("+-");
        if(symbol != std::string::npos){
            return false;
        }

        auto n_num = index.find_first_not_of("0123456789");
        if(n_num != std::string::npos || index.size() == 0){
            return false;
        }

        return true;
    }
};

class Solution_offer16 {
public:
    double myPow(double x, int n) {
        long index = n;
        bool minus = false;
        if(index < 0){
            minus = true;
            index = -index;
        }

        double res = caculate(x,index);
        if(minus){
            res = 1.0/res;
        }
        return res;

    }


    double caculate(double x,long n){
        if(n == 0){
            return 1;
        }

        double res = 0,tmp;
        tmp = caculate(x,n >> 1);
        res = tmp * tmp;
        if(n & 0x1){
            res = res * x;
        }

        return res;
    }
};

class Solution_offer12 {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        if(board.size() ==0 || board[0].size() == 0 || word.size() == 0){
            return false;
        }
        std::vector<bool> hash_table(board.size() * board[0].size());

        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(board[i][j] == word[0]){
                    bool res = is_exist(board,hash_table,i,j,word,0);
                    if(res){
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool is_exist(std::vector<std::vector<char>>&board,std::vector<bool> & hash_table,int row,int column,
                  const std::string &word,int pos){
        if(pos == word.size()){
            return true;
        }

        if(row < 0 || row >= board.size() || column < 0 || column >= board[0].size()){
            return false;
        }

        if(hash_table[row * board[0].size() + column] != false ||
           board[row][column] != word[pos]){
            return false;
        }

        hash_table[row * board[0].size() + column] = true;
        bool res = false;

        res = is_exist(board,hash_table,row - 1,column,word,pos + 1);

        if(!res){
            res = is_exist(board,hash_table,row + 1,column,word,pos + 1);
        }

        if(!res){
            res = is_exist(board,hash_table,row,column-1,word,pos + 1);
        }

        if(!res){
            res = is_exist(board,hash_table,row,column+1,word,pos + 1);
        }

        hash_table[row * board[0].size() + column] = false;
        return res;
    }
};

class Solution_offer11 {
public:
    int minArray(std::vector<int>& numbers) {
        if(numbers[0] == numbers[numbers.size()-1]){
            return min_array(numbers);
        }

        int left = 0,right = numbers.size() - 1;
        int mid = (left + right) / 2;
        int min_n = numbers[0];
        while(left < right){
            if(left + 1 == right){
                min_n = std::min(numbers[left],numbers[right]);
                break;
            }
            if(numbers[mid] >= numbers[left]){
                left = mid;
            }

            if(numbers[mid] <= numbers[right]){
                right = mid;
            }

            mid = (left + right)/2;

        }

        return min_n;

    }


    int min_array(std::vector<int> & numbers){
        int m = numbers[0];
        for(int i =1;i<numbers.size();++i){
            if(m > numbers[i]){
                m = numbers[i];
            }
        }

        return m;
    }
};


class CQueue {
public:
    CQueue() {

    }

    void appendTail(int value) {
        s1.push(value);
    }

    int deleteHead() {

        if(s1.empty() && s2.empty()){
            return -1;
        }

        int res;
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        res = s2.top();
        s2.pop();
        return res;
    }
private:
    std::stack<int> s1,s2;
};



class Solution_offer7 { //!!!一定要注意，建树的时候只能根据计算子树的节点个数，不能直接传递索引到的下标
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        if(preorder.size() != inorder.size() || preorder.size() == 0){
            return nullptr;
        }

        return buildTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }


    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder,int p_left,int p_right,
                        int i_left,int i_right){
        if(p_left > p_right || i_left > i_right){
            return nullptr;
        }

        int r_idx = i_left;
        while(preorder[p_left] != inorder[r_idx] && r_idx <= i_right){
            ++r_idx;
        }

        TreeNode* root = new TreeNode(preorder[p_left]);
        root->left = buildTree(preorder,inorder,p_left+1,p_left + r_idx - i_left,i_left,r_idx - 1);
        root->right = buildTree(preorder,inorder,p_left + r_idx - i_left + 1,p_right,r_idx+1,i_right);

        return root;

    }
};


// Definition for singly-linked list.
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution_offer6 {
//public:
//    std::vector<int> reversePrint(ListNode* head) {
//        std::vector<int> res;
//        ListNode * p = head;
//        while(p){
//            res.push_back(p->val);
//            p=p->next;
//        }
//
//        std::reverse(res.begin(),res.end());
//        return res;
//    }
//};


class Solution_offer5 {
public:
    std::string replaceSpace(std::string s) {
        int len = s.size();
        for(auto val : s){
            if(val == ' '){
                len += 2;
            }
        }

        std::string res(len,' ');
        for(int i = s.size()-1,j = res.size()-1;i>=0;--i){
            if(s[i] == ' '){
                res[j--] = '0';
                res[j--] = '2';
                res[j--] = '%';
            }else{
                res[j--] = s[i];
            }
        }

        return res;
    }
};

class Solution_offer4 {
public:
    bool findNumberIn2DArray(std::vector<std::vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0){
            return false;
        }
        int top = 0,right = matrix[0].size() - 1;

        while(top < matrix.size() && right >= 0){
            if(matrix[top][right] > target){
                --right;
            }else if(matrix[top][right] < target){
                ++top;
            }else{
                return true;
            }
        }
        return false;
    }
};

class Solution_offer3 {
public:
    int findRepeatNumber(std::vector<int>& nums) {
        std::vector<bool> is_concur(nums.size());

        for(auto val : nums){
            if(is_concur[val]){
                return true;
            }
            is_concur[val] = true;
        }

        return false;
    }
};


int get_ulgy_number(int index);

std::string find_min_combine_number(std::vector<std::string> numbers);
unsigned long long count_one(int num,int k);

int continuous_max_sum(const std::vector<int>& numbers);

void get_last_numbers(const std::vector<int> &numbers,std::set<int,std::greater<int>> &last_k,int k);

bool more_than_half(std::vector<int> &number,int & result);

void permuation(std::string &str);

struct binary_t_node{
    int _val;
    binary_t_node * _pleft;
    binary_t_node * _pright;
    binary_t_node():_val(0),_pleft(nullptr),_pright(nullptr){}
    binary_t_node(int val):_val(val),_pleft(nullptr),_pright(nullptr){}
};

binary_t_node * convert_binary_search_tree_to_list(binary_t_node * head);
void binary_search_tree_insert(binary_t_node * &head,int val);
void print_binary_search_tree(binary_t_node * root);
void print_binary_list(binary_t_node * root);


struct complex_forward_list_node{
    int _val;
    complex_forward_list_node * _pnext;
    complex_forward_list_node * _psib;
    complex_forward_list_node(int val):_val(val),_psib(nullptr),_pnext(nullptr){};
    complex_forward_list_node():_val(0),_pnext(nullptr),_psib(nullptr){};
};

void destroy_complext_forward_list(complex_forward_list_node * head);
void print_complext_forward_list(complex_forward_list_node * head);
complex_forward_list_node * create_complext_forward_list(const std::vector<int> &list,std::vector<int> &sib);
complex_forward_list_node * copy_complex_forward_list(complex_forward_list_node * head);



#endif //C___AFTER_26_H
