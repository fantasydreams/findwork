//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//
//#include <iostream>
//#include <string>
//#include <sstream>
//
//using namespace std;
//
//
//
//void dfs(vector<vector<int>> &map,vector<vector<int>> is_visited,int line,int col,int step,int n_monster,
//         bool &is_through,int& min_step){
//
//    if(n_monster == 0){
//        is_through = true;
//        if(min_step > step) min_step = step;
//        return;
//    }
//
//    if(line < 0 || line >= map.size() || col >= map[0].size() || col < 0 || is_visited[line][col+1]) return;
//
//    if(map[line][col] == 0)return;
//    if(map[line][col] > 0){
//        ++step;
//        if(map[line][col] > 1) --n_monster;
//        is_visited[line][col] = true;
//        dfs(map,is_visited,line-1,col,step,n_monster,is_through,min_step);
//        dfs(map,is_visited,line+1,col,step,n_monster,is_through,min_step);
//        dfs(map,is_visited,line,col-1,step,n_monster,is_through,min_step);
//        dfs(map,is_visited,line,col+1,step,n_monster,is_through,min_step);
//        is_visited[line][col] = false;
//    }
//
//
//
//}
//
////int main(){
////    cout << ((unsigned int)(-1) >> 1);
////    cout << endl << INT_MAX;
////}
//
//int main(){
//    vector<vector<int>> map;
//    vector<vector<int>> is_visited;
//    int n_monster = 0;
//    string line;
//    int i=0;
//    while(getline(cin,line)){
//        stringstream ss(line);
//        vector<int> tmp;
//        unsigned long long num;
//        int len = 0;
//        while(ss >> num){
//            if(num > 1){
//                ++n_monster;
//                tmp.push_back(2);
//            }else if(num == 1) tmp.push_back(1);
//            else tmp.push_back(0);
//            ++len;
//        }
//        vector<int> visit(len,false);
//        is_visited.push_back(visit);
//        map.push_back(tmp);
//        if(++i == 3) break;
//    }
//
//    bool is_through = false;
//    int min_step = INT_MAX;
//    dfs(map,is_visited,0,0,0,n_monster,is_through,min_step);
//    if(is_through) cout << min_step-1;
//    else cout << -1;
//
//    return 0;
//}
//
//
////int main(){
////
////    int n; cin >> n;
////    if(n == 0)cout << 0;
////    vector<string> matrix;
////    vector<vector<int>>dp;
////    int max_len=0;
////
////    for(int i=0;i<n;++i){
////        string str; cin >> str;
////        vector<int> dp_elem(str.size()); int num;
////        for(int i=0;i<str.size();++i){
////            dp_elem[i] = (str[i] == '1' ? 1 : 0);
////            if(str[i] == '1')max_len = 1;
////        }
////        matrix.push_back(str);
////        dp.push_back(dp_elem);
////    }
////
////
////    for(int i=1;i<n;++i){
////        for(int j=1;j<matrix[i].size();++j){
////            if(matrix[i][j] == '1' && matrix[i-1][j-1] == '1'
////               && matrix[i-1][j] == '1' && matrix[i][j-1] == '1'){
////
////                int line = 0,col = 0;
////                for(int k=j-1; k >=0 && matrix[i][k] == '1';--k) ++line;
////                for(int k=i-1; k >=0 && matrix[k][j] == '1';--k) ++col;
////                dp[i][j] = min(min(dp[i-1][j-1],line),col) + 1;
////
////                if(dp[i][j] > max_len) max_len = dp[i][j];
////            }
////        }
////    }
////    cout << max_len * max_len;
////
////    return 0;
////}
//
//


//#include <iostream>
//#include <string>
//#include <vector>
//using namespace  std;
//
//bool is_alpha(const char c){
//    if ((c >= 'A' && c <='Z') || (c>='a' && c <= 'z')) return true;
//    return false;
//}
//
//string reverse_string(const string &  str){
//    vector<string> str_arry;
//    string word;
//    bool pre_alpha = true;
//    for(int i=0;i<str.size();++i){
//        if(is_alpha(str[i])){
//            word += str[i];
//            pre_alpha = true;
//        }else{
//            if(pre_alpha == false && str[i] == str[ i - 1]) {
//                word += str[i - 1];
//                word += str[i];
//                pre_alpha = true;
//            }
//            pre_alpha = false;
//        }
//    }
//    if(word.size() > 0) str_arry.push_back(word);
//
//    string res ;
//    for(int i=str.size()-1;i >= 0;--i){
//        res += str_arry[i];
//        if(i != 0) res += ' ';
//    }
//
//    return res;
//}
//
//
//int main(){
//
//    string str = "a--m";
//    cout << reverse_string(str);
//    //cout << is_alpha('-');
//    return 0;
//}


#include <iostream>
#include <queue>

using namespace  std;

struct TreeNode{
    int val;
    TreeNode * left, *right;
    TreeNode(){}
    ~TreeNode(){}
    TreeNode(int _val) :val(_val){}
    TreeNode(int _val, TreeNode * _left, TreeNode * _right) :val(_val), left(_left), right(_right){}
};

int getMaxWidth( TreeNode * root){
    if(!root) return 0;
    vector<TreeNode *> q;
    vector<TreeNode *> back;
    q.push_back(root);
    size_t _size = 1;
    size_t _max_size = 0;
    while(true){
        size_t start = 0;
        while(start < q.size()){
            if(q[start] == nullptr){
                ++start;
                continue;
            }
            break;
        }
        size_t end = q.size();
        while(end >=0 ){
            if(q[end] == nullptr){
                --end;
                continue;
            }
            break;
        }
        if(start > end) {
            break;
        }else{
            _max_size = _max_size > end - start + 1 ? _max_size : end - start + 1;
        }
        for(size_t i = start; i < end; ++i){
            TreeNode * node = q[i];
            if(node == nullptr) {
                back.push_back(nullptr);
                back.push_back(nullptr);
            }else{
                back.push_back(node->left);
                back.push_back(node->right);
            }
        }
        q.clear();
        swap(q,back);
    }
    return _max_size;
}

int main(){


    return 0;
}



