

#include "cmake-build-debug/header/project.h"
#include "cmake-build-debug/header/test.h"



#include <iostream>
#include <vector>
using namespace std;


int main(){

//    Solution576 instance;
//    instance.checkInclusion("adc","dcda");
//    cout << instance.checkInclusion("hello","ooolleoooleh");
//    cout << instance.checkInclusion("ky","ainwkckifykxlribaypk");
    Solution438 s;
    s.findAnagrams("cbaebabacd","abc");
    return 0;
}

//int main(){
//    Solution_5 instance;
//    cout << instance.longestPalindrome("abccdfdwqweewqwqeewqqweewq");
//    return 0;
//}


//class vbase{
//public:
//    vbase(){};
//    virtual void print(){};
//private:
//    int a;
//};
//
//class vderive1:vbase{
//public:
//    vderive1(){};
//    virtual void print(){};
//    virtual void test(){};
//private:
//    int de;
//};
//
//class vderive2:vderive1{
//public:
//    vderive2(){};
//    virtual void print(){};
//    virtual void test(){};
//private:
//    int d2;
//};

//int strcasecmp(const char *s1, const char *s2){
//    if(!s1 && !s2) return 0;
//
//    int s1_idx = 0,s2_idx = 0;
//    while(s1[s1_idx] && s2[s2_idx]){
//        char c_s1 = s1[s1_idx],c_s2 = s2[s2_idx];
//        if('a'<=c_s1 && c_s1 <= 'z') c_s1-=32;
//        if('a'<=c_s2 && c_s2 <= 'z') c_s2-=32;
//        if(c_s1 != c_s2) return c_s1-c_s2;
//
//        ++s1_idx,++s2_idx;
//    }
//
//    if(s1[s1_idx]) return s1[s1_idx];
//    if(s2[s2_idx]) return -s2[s2_idx];
//
//    return 0;
//}
//
//int find_bysequece(int array[],int left,int right){
//    int _min = array[left];
//    for(int i=left;i<right;++i){
//        if(_min > array[left]) _min = array[i];
//    }
//    return _min;
//}



//int findmin( int array[], int count ){
//
//    int low = 0,high = count-1,mid;
//    if(array[low] == array[high]) return find_bysequece(array,low,high);
//    while(low <= high){
//        if(low + 1 == high) return min(array[low],array[high]);
//
//        mid = (low + high) / 2;
//        if(array[mid] >= array[low]) low = mid;
//        if(array[mid] <= array[high]) high = mid;
//    }
//
//}

//struct Node{
//    struct Node *left,*right;
//    int val;
//};
//
//bool get_path(Node* root,vector<Node*> &path,int val){
//    if(!root) return false;
//
//    path.push_back(root);
//    if(root->val == val) return true;
//
//    bool finded = get_path(root->left,path,val);
//    if(!finded)finded = get_path(root->right,path,val);
//    if(finded) return finded;
//
//    path.pop_back();
//    return finded;
//}

//Node * getAncestors（Node * root, int a, int b, int c)
//{
//vector<vector<int>> three_path(3);
//get_path(root,three_path[0],a); //因为a,b,c都存在，所以不用判断返回的是false
//get_path(root,three_path[1],b);
//get_path(root,three_path[2],c);
//
//int lca_idx = 0;
//int len = min(three_path[0].size(),three_path[1].size());
//while(lca_idx < len && (three_path[0][lca_idx] == three_path[1][lca_idx]))++lca_idx;
//
//len = min(lca_idx,three[2].size());
//lca_idx = 0;
//while(lca_idx < len && (three_path[0][lca_idx] == three_path[2][lca_idx]))++lca_idx;
//
//return three_path[0][lca_idx];
//
//}

//double find_median(const vector<int> &A, const vector<int> & B){
//    if(A.size() == 0 &&  B.size() == 0) return 0;
//
//    vector<int> arr(A.size() + B.size());
//    size_t A_idx = 0,B_idx = 0,res_idx = 0;
//
//    while(A_idx < A.size() && B_idx < B.size()){
//        if(A[A_idx] < B[B_idx]) arr[res_idx++] = A[A_idx++];
//        else arr[res_idx++] = B[B_idx++];
//
//    }
//
//    while(A_idx < A.size()) arr[res_idx++] = A[A_idx++];
//    while(B_idx < B.size()) arr[res_idx++] = B[B_idx++];
//
//    if((arr.size() & 0x1) == 0){
//        return ((double)(arr[arr.size() / 2]) + arr[arr.size() / 2 - 1]) / 2;
//    }
//    return arr[arr.size() / 2];
//}


//#define is_one(n, i) ((n) & 1 << (i))
//
//int find_anyone(vector<int> &arr){
//    for(int i = 0; i < 32; i++){
//        int tmpA = 0,tmpB = 0, countA = 0,countB = 0;
//        for(int j = 0; j < arr.size(); j++){//遍历数组
//            if(is_one(arr[j], i)){
//                tmpA ^= arr[j];
//                countA++;
//            }else{
//                tmpB ^= arr[j];
//                countB++;
//            }
//        }
//        if(countA & 0x1){
//            if(0 == tmpB) continue;
//            else return tmpA;
//        }else{
//            if(0 == tmpA) continue;
//            else return tmpB;
//        }
//    }
//}
//
//#include <iostream>
//#include <queue>
//using namespace std;
//
//void quicksort(int *arr, int length){
//    if (arr == NULL || length < 1)
//    {
//        return;
//    }
//    int i = 0;
//    int j = length - 1;
//    int temp = arr[j];
//    while (i < j){
//        while ((i < j) && (arr[i] >= temp)){
//            i++;
//        }
//        if (i < j){
//            arr[j--] = arr[i];
//        }
//        while ((i < j) && (arr[j] <= temp)){
//            j--;
//        }
//        if (i < j){
//            arr[i++] = arr[j];
//        }
//    }
//    arr[i] = temp;
//    quicksort(arr, i);
//    quicksort(arr+i+1, length-i-1);
//}
//
//bool findpartition(int *arr, int length){
//    int sum = 0;
//    cout << "原始数组为: " << endl;
//    for (int i = 0; i < length; i++){
//        cout << arr[i] << " ";
//        sum += arr[i];
//    }
//    cout << endl;
//    quicksort(arr, length);
//    int Max_subArray = length;
//    for (int i = Max_subArray; i > 1; --i){
//        if (0 == sum % i){
//            int aSum = sum / i;
//            int pBegin = 0;
//            int pEnd = length - 1;
//            int j = 0;
//            queue<int> q;
//            for (j = i; j > 0; j--){
//                //如果相等
//                if (aSum == arr[pBegin]){
//                    q.push(arr[pBegin]);
//                    q.push(-1);
//                    ++pBegin;
//                }
//                    //如果大于
//                else if (aSum > arr[pBegin]){
//                    q.push(arr[pBegin]);
//                    int temp = arr[pBegin];
//                    ++pBegin;
//                    while (temp < aSum){
//                        temp += arr[pEnd];
//                        q.push(arr[pEnd]);
//                        --pEnd;
//                    }
//                    if (aSum == temp){
//                        q.push(-1);
//                    }
//                    else{
//                        break;
//                    }
//                }
//                    //如果小于
//                else{
//                    break;
//                }
//            }
//            if (j == 0){
//                while (!q.empty()){
//                    if (-1 != q.front()){
//                        cout << q.front() << " ";
//                        q.pop();
//                    }
//                    else{
//                        cout << endl;
//                        q.pop();
//                    }
//                }
//                cout << "Max_subArray: " << i << endl;
//                return true;
//            }
//        }
//    }
//    return false;
//}
//
////#define N 5000000
//
//void findQHNums(int n) {
//    int* sum = new int[n];
//    memset(sum, 0, n * sizeof(int));
//
//    //N内的真因子
//    for (int i = 1; i <= n / 2; ++i) {
//        //计算以i为真因子的数（i的倍数）的亲和值
//        for (int j = i * 2; j <= n; j += i) {
//            sum[j] += i;
//        }
//    }
//
//    for (int i = 2; i < n; ++i) {
//        if (sum[i] > i && sum[i] <= n && sum[sum[i]] == i) {
//            cout << i << ' ' << sum[i] << endl;
//        }
//    }
//}

//
//class static_{
//private:
//    static int a;
//public:
//    static int func(){
//        return a;
//    }
//};
//
//int static_::a = 0;
//int main(){
////    int array[] = {2,4,6,3,3};
////    findpartition(array, sizeof(array)/sizeof(array[0]));
//
//    Solution_18_a ins;
//    vector<int> a = {0,2,2,2,10,-3,-9,2,-10,-4,-9,-2,2,8,7};
//    ins.fourSum(a,6);
//    return 0;
//}

/*
int main(){

    int top=0,n;
    cin >> n;
    vector<int> h;
    vector<int> r;
    vector<int> l;
    stack<int> st;
    for(int i=0;i<n;++i)
    {
        //往左边找小于等于h[i]的坐标的最大值
        int num;
        cin >> num;
        h.push_back(num);
        while(top>0&&h[st.top()]>=h[i]) --top;
        l.push_back(top==0?0:st.top()+1);
        st.push(i);
    }
    top=0;
    for(int i=n-1;i>=0;--i)
    {
        //往右边找大于h[i]的坐标的最小值
        while(top>0&&h[st.top()]>=h[i]) --top;
        r.push_back(top==0?n:st.top());
        st.push(i);
    }
    long long ans=0;
    for(int i=0;i<n;++i)
        ans=max(ans,(long long)h[i]*(r[i]-l[i]));
    cout << ans;
    return 0;

}
 */



//struct B{
//    int a;
//    int b[];
//};
//template <class A, class B, class U = my_less<A,B>>
//bool f(A a, B b, U u = U())
//{
//    return u(a, b);
//}
//
//
//int p(const int && a){
//    cout << a;
//}

//int main(){
//
////    vector<int> a = {1,2,3,4};
////    for(auto iter = a.begin();iter != a.end();++iter){
////        cout<< *iter;
////    }
//    cout << sizeof(list<int>);
//
//    return 0;
//}

//int main()
//{
//    std::cout << std::boolalpha;
//    std::cout << f(5, 20) << '\n';
//    std::cout << f(100, 10) << '\n';
//}

//int main(){
//    int a = 0;
//    const_call(a);

//    print("hello");
//    double d; float f; char c;
//    calc(c, 'c');
//    calc(d, f);
//    fcn(c, 'c');
//    //fcn(d, f);

//    cout << my_compare("hello","word");

//    int * p_raw = (int *)(::operator new((size_t)(sizeof(int) * 4)));
//    int * p_int = new(p_raw) int(1);
//    cout << p_raw <<endl
//        <<p_int;
    //test_alloc();
    //cout << my_less1("hello","word");
//    B c[2];
//    //cout << (unsigned long )b.b;
//
//
//    cout  << sizeof(c);
//
//    return 0;
//
//}

//int main(){

//    Solution_offer4 instance;
//    vector<vector<int>> num = {
//            {1,4,7,11,15},
//            {2,5,8,12,19},
//            {3,6,9,16,22},
//            {10,13,14,17,24},
//            {18,21,23,26,30}
//    };
//    cout << instance.findNumberIn2DArray(num,18)<<endl;
//    std::string res(10,' ');
//    Solution_offer7 ins;
//    vector<int> pre = {1,2,3};
//    vector<int> in = {3,2,1};
//    TreeNode * head = ins.buildTree(pre,in);
//    vector<int> a = {1,2,3,4,5};
//    cout << rotate_min(a) << endl;

//    Solution_offer12 instance;
//    vector<vector<char>> num;
//    vector<char> table = {'C','A','A'};
//    vector<char> table1 = {'A','A','A'};
//    vector<char> table2 = {'B','C','D'};
//    num.push_back(table);
//    num.push_back(table1);
//    num.push_back(table2);
//    cout << instance.exist(num,"AAB");

//    Solution_offer16 instance;
//    cout << instance.myPow(2.0,-2);
//
//    string s = "123124234wqwe";
//    auto pos = s.find_last_not_of("+-.e1234567890");
//    cout << s[pos];

//    Solution_offer22 ins;
//    vector<int> num = {1};
//    listNode * head = ins.create_forward_list(num);
//    listNode * res = ins.getKthFromEnd(head,1);
//
//}



//int main(){
//
////    vector<int> numbers ={1,-2,3,10,-4,7,2,-5};
////    cout << continuous_max_sum(numbers);
////    cout << count_one(2134,1) << endl
////    <<count_one(21345,1);
//    vector<string> num = {"3","32","321"};
//    cout << find_min_combine_number(num);
//    return 0;
//}

//int main(){
//    vector<int> numbers = {};
//    set<int,greater<int>> last_k;
//    get_last_numbers(numbers,last_k,1);
//    sort(numbers.begin(),numbers.end());
//
//    print_through_iterator(numbers.cbegin(),numbers.cend());cout << endl;
//    print_through_iterator(last_k.crbegin(),last_k.crend());
//
//    return 0;
//}

//int main(){
//
//    vector<int> number = {1,2,3,2,2,2,5,4,2,1};
//    int res = 0;
//    if(more_than_half(number,res)){
//        cout << res << endl;
//    }else{
//        cout << "not found!";
//    }
//
//    return 0;
//}

//int main(){
//
//    string str = "123456";
//    permuation(str);
//    return 0;
//}




//int main(){
//
//    vector<int> list = {5,1,2,6,9,8,4,3,7};
//    binary_t_node * root = nullptr;
//    for(auto val : list){
//        binary_search_tree_insert(root,val);
//    }
//
//    print_binary_search_tree(root);cout << endl;
//    binary_t_node * l = convert_binary_search_tree_to_list(root);
//    print_binary_list(l);
//
//    return 0;
//}


//int main(){
//
//    vector<int> list = {1,2,3,4,5,6,7,8,9};
//    vector<int> sib = {1,0,3,2,5,-1,-1,6,-1};
//
//    complex_forward_list_node * head = create_complext_forward_list(list,sib);
//    complex_forward_list_node * new_head = copy_complex_forward_list(head);
//    print_complext_forward_list(head);cout << endl;
//    print_complext_forward_list(new_head);
//    destroy_complext_forward_list(head);
//    destroy_complext_forward_list(new_head);
//    return 0;
//}


//int main() {
//    class rebuild_binary_tree<int> instance;
//    vector<int> case1_pre = {1, 2, 4, 7, 3, 5, 6, 8};
//    vector<int> case1_in = {4, 7, 2, 1, 5, 3, 8, 6};
//    binary_tree_node<int> *root_1 = instance.RBT(case1_pre, case1_in, 0, case1_pre.size() - 1, 0, case1_in.size() - 1);
//
//    vector<int>path;
//    int cur_sum = 0;
//    find_sum_path(root_1,18,cur_sum,path);
//
//    instance.destory_binary_tree(root_1);
//}

//int main(){
//
//    vector<int> data = {1,2,3,4,5,6,7,8,9};
//    forward_list_node * head = create_forward_list(data);
//    print_through_pointer(head);cout <<endl;
//
//    head = reverse_forward_list(head);
//    print_through_pointer(head);cout << endl;
//
//    forward_list_node * new_head = nullptr;
//    print_through_pointer(new_head);cout << endl;
//
//    vector<int> pdata = {1};
//    forward_list_node * p = create_forward_list(pdata);
//    p = reverse_forward_list(p);
//    print_through_pointer(p);
//    return 0;
//}


//int main(){
//
//    vector<int> se = {5,7,6,11,10,8};
//    cout << is_binary_search_tree_post(se);
//
//    vector<int> se1 = {7,4,6,5};
//    cout << is_binary_search_tree_post(se1);
//    return 0;
//}


//int main(){
//    vector<int> stack_in = {1,2,3,4,5};
//    vector<int> stack_out = {4,3,5,2,1};
//    cout << is_stack_pop_sequence(stack_in,stack_out) <<endl;
//    return 0;
//}

//int main(){
//    min_stack<int> min_s;
//    int a[] = {9,4,6,8,2,3,1};
//
//    for(auto val : a){
//        min_s.push(val);
//        cout << min_s.get_min()<< " ";
//    }
//    cout << endl;
//
//    while(!min_s.empty()){
//        cout << min_s.get_min() << " ";
//        min_s.pop();
//    }
//
//    return 0;
//}


//int main(){
////    class rebuild_binary_tree<int> instance;
////    vector<int> case1_pre = {1,2,4,7,3,5,6,8};
////    vector<int> case1_in = {4,7,2,1,5,3,8,6};
////    binary_tree_node<int> * root_1 = instance.RBT(case1_pre,case1_in,0,case1_pre.size()-1,0,case1_in.size()-1);
////
////    mirror_tree(root_1);
////
////    instance.pre_traverse(root_1);
////
////    instance.destory_binary_tree(root_1);
//
////    vector<vector<int>> matrix1 = {
////            {1,2,3,4,5},
////            {6,7,8,9,10},
////            {11,12,13,14,15},
////            {16,17,18,19,20},
////            {21,22,23,24,25}
////    };
////
////    print_matrix_by_circle(matrix1);
//
//    vector<vector<int>> matrix = {
//            {1,2,3},
//            {4,5,6},
//            {7,8,9},
//            {10,11,12},
//            {13,14,15}
//
//    };
//
//    print_matrix_by_circle(matrix);cout << endl;
//
//    vector<vector<int>> matrxi = {
//            {1,2,3,4,5},
//            {6,7,8,9,10},
//            {11,12,13,14,15}
//    };
//
//    print_matrix_by_circle(matrxi);
//
//    return 0;
//}


//int main(){
//
//
//    class rebuild_binary_tree<int> instance;
//    vector<int> case1_pre = {1,2,4,7,3,5,6,8};
//    vector<int> case1_in = {4,7,2,1,5,3,8,6};
//
//    vector<int> case1_pre2 = {3,5,6};
//    vector<int> case1_in2 = {5,3,6};
//
//    binary_tree_node<int> * root_1 = instance.RBT(case1_pre,case1_in,0,case1_pre.size()-1,0,case1_in.size()-1);
//    binary_tree_node<int> * root_2 = instance.RBT(case1_pre2,case1_in2,0,case1_pre2.size()-1,0,case1_in2.size()-1);
//
//    binary_tree_node<int> * res = has_subtree(root_1,root_2);
//    if(res){
//        cout << res->get_value() <<endl;
//    }else{
//        cout << "not found!" << endl;
//    }
//    vector<int> case1_pre3 = {4,5,6};
//    vector<int> case1_in3 = {5,4,6};
//    binary_tree_node<int> * root_3 = instance.RBT(case1_pre3,case1_in3,0,case1_pre3.size()-1,0,case1_in3.size()-1);
//    res = has_subtree(root_1,root_3);
//    if(res){
//        cout << res->get_value() <<endl;
//    }else{
//        cout << "not found!" << endl;
//    }
//
//
//    res = has_subtree(root_1,nullptr);
//    if(res){
//        cout << res->get_value() <<endl;
//    }else{
//        cout << "not found!" << endl;
//    }
//
//
//
//
//    return 0;
//}



//int main(){
//
//    vector<int> case_1 = {1,4,7,9,11,16,17,18,20};
//    vector<int> case_2 = {0,2,3,4,5,6,7,8,9,10,12,19};
//    forward_list_node *head_1 = create_forward_list(case_1);
//    forward_list_node *head_2 = create_forward_list(case_2);
//    forward_list_node * res = merge_two_sorted_list(head_1,head_2);
//
//    for(auto iter = res;res;res = res->_next){
//        cout << res->_val <<" ";
//    }
//
////    forward_list_node *k = find_last_k_node(head,5);
////    cout << k->_val << endl;
//
//
////    k = find_last_k_node(head,20);
////    if(!k){
////        cout << "nullptr" << endl;
////    }
//
//    destory_lsit(res);
//
//    return 0;
//}

//offer 调整数组
//int main(){
//    int a[] = {1,2,4,2,2,1,3,6,7,6,5,34,5,23,4,8,13,27};
//    //char str[] = {"123"};
//    int * p = a;
//
//    //cout << sizeof(str); str能输出正确的大小，但是其他类型就不行，比如整型数组
//    //cout << sizeof(a) ; 输出一个不是a数组大小的值
//    //swap(p[0],p[1]);
//    ajust_array(a,18,isEvent);
//    print_through_pointer(a,18);
//    return 0;
//}

//class B{};
//
//int main()
//{
////    Foo().sorted(); // call "&&"
////    Foo f;
////    f.sorted(); // call "const &"
//
////
////    sale_data a,b,c;
////    cin >> a >> b;
////    c = b;
////    cout << (a + b + c);
//
//    //cout << sizeof(B);
//    const int &b = 1;
//    cout << b <<endl;
//
//
//
//}

//int main(){
//
////    my_shared_ptr<int> t;
////    cout << t.use_count() << endl;
////
////    my_shared_ptr<int> q(t);
////    cout << t.use_count() << endl;
//
////    my_shared_ptr<int> m(new int(0));
////    cout << m.use_count() << endl;
////
////    my_shared_ptr<int> n = m;
////    cout << n.use_count() << " " << m.use_count() << endl;
////
//
//
////    test t;
////    test p(t);
//    //test m(t,p);
//
////    hasPtr p[] = {{"12",1},{"34",2},{"56",1}};
////    //cout << (p[0] < p[1]);
////    sort(p,p+2);
//
//
//    return 0;
//
//};

//12.10
//int main(){
//
//    string str ="test";
//    string str1(str);

    //12.30
//    TextQuery t("./file/primer/11.3");
//    QueryResult res = t.query("the");
//    Query_res_print(cout,res);




//    Text t("./file/primer/11.3");
//    //print_vector(t);
//    //print_word(t);
//    t.query("the");

//    vector<string> str = {"sharwen","is","a","clever","boy","!"};
//    allocator<string> alloc;
//    string * p = alloc.allocate(str.size() * 2);
//    auto q = uninitialized_copy(str.cbegin(),str.cend(),p);
//    auto end = uninitialized_fill_n(q,str.size(),"yes!");
//
//    auto begin = p;
//    while(begin != end){
//        cout << *begin << " ";
//        alloc.destroy(begin++);
//        //begin++;
//    }
//
//    alloc.deallocate(p,str.size() * 2);

    //12.24
    //is_string();


    //12.23
//    char * s1 = "1234567890";
//    char * s2 = "abcdefghijk";
//    char * str = concate_charstring(s1,s2);
//    cout << str;
//
//    delete[] str;
//    cout << "deleted" << endl;
//
//    string str1 = "hello";
//    string str2 = " word!";
//    cout << concate_string(str1,str2) << endl;



//    shared_ptr<int> p(new int(24));
//    cout << *p <<" "<< p.use_count();
//
//    shared_ptr_process(p);
//
//
//    cout << endl;
//
//    unique_ptr<int> up = unique_ptr_test(46);
//    cout << *up <<endl;



//    return 0;
//}

//int main(){
//    //12.6
//    auto p = new_int_vec();
//    ifstream in("./file/primer/12.6");
//    if(!in) return 0;
//
//    istream_iterator<int> is_in(in),eof;
//    while(is_in != eof){
//        p->push_back(*is_in++);
//    }
//    in.close();
//    print_through_iterator(p->cbegin(),p->cend());cout << endl;
//
//    //12.7
//    auto shared_p = new_int_vec_shared_ptr();
//    in.open("./file/primer/12.6");
//    if(!in) return 0;
//    istream_iterator<int> is_in_1(in);
//    while(is_in_1 != eof){
//        shared_p->push_back(*is_in_1++);
//    }
//    in.close();
//    print_through_iterator(shared_p->cbegin(),shared_p->cend());
//
//    delete p;
//
//}

//int main(){
//    //shared_ptr_text();
//    vector<int> *a = new vector<int>{1,2,3,4,5};
//    print_through_iterator(a->begin(),a->end());
//
//    const int * p = new const int(1024);
//    cout  << *p <<endl;
//    return 0;
//}

//int main(){
//
//    strBolb b1 = {"sharwen","is","a","clever","boy","!"};
//    const strBolb cb = {"const","sharwen"};
//    cout << b1.size();
//
//    string s = b1.front();
//    string cs = cb.front();
//
//
//    return 0;
//}

//int main(){
//    //10.33
//    exchange_text_map("./file/primer/10.33","./file/primer/rule");
//
//    //10.38
//    exchange_text_unorder_map("./file/primer/10.33","./file/primer/rule");
//
//    return 0;
//}

//int main(){
//    multimap<string,int> MP;
//    MP.insert({"sharwen",3});
//    MP.insert({"sharwen",2});
//    MP.insert({"sharwen",1});
//    MP.insert({"is",4});
//    MP.insert({"a",5});
//    MP.insert({"clever",6});
//    MP.insert({"boy",7});
//    MP.insert({"boy",7});
//    MP.insert({"!",8});
//
//    //11.31
////    string key = "sharwen";
////    erase_multimap_by_key(MP,key);
////    print_map_or_pair(MP.begin(),MP.end());
////
////    erase_multimap_by_key(MP,key);
////    print_map_or_pair(MP.begin(),MP.end());
//
//    //10.32
//    print_map_or_pair(MP.begin(),MP.end());cout << endl;
//    print_multimap_by_dict_order(MP);
//
//    return 0;
//}

//int main(){
//
//    map<string,int> Map = {
//            {"boy",5},
//            {"sharwen",1},
//            {"clever",4},
//            {"a",3},
//            {"is",2}
//    };
//
//    vector<pair<string,int>> res;
//    map_sort_by_maptype(Map,res);
//    print_map_or_pair(res.cbegin(),res.cend());
//
//    auto ret = Map.insert({"yes!",0});
//
//    auto iter = Map.erase(--Map.end());
//    if(iter == Map.end()){
//        cout << "End!";
//    }
//
//    print_map_or_pair(Map.begin(),Map.end());
//
//
//    return 0;
//}

//int main(){
//
//    //11.13
//    vector<pair<string,int>> vec;
//    make_pair_string_int(vec);
//    print_map_or_pair(vec.cbegin(),vec.cend());
//    return 0;
//}

//int main(){
//
//    //11.3
//    map<string,unsigned int> dict;
//    set<string> exclude = {"*","before","iterators","-","==:","a","an","as","be","by","i","of"};
//    count_words("./file/primer/11.3",dict,exclude);
//    print_map(dict.cbegin(),dict.cend());
//
////    for(auto iter = dict.cbegin();iter != dict.cend();++iter){
////        cout << iter->first<< ":" << iter->second << endl;
////    }
//    return 0;
//}

//int main(){
//
//    //10.42
//    list<string> text;
//    list_unique(text,"./file/primer/10.42");
//    print_through_iterator(text.cbegin(),text.cend());
//
//}

//int main(){
//
//    //10.34 - 10.37
//    vector<string> text = {"sharwen","is","a","celver","boy","!"};
//    print_vector(text);
//    reverse_print_vector(text);
//    reverse_print_vector_common_iterater(text);
//
//    vector<int>  numbers = {0,1,2,3,4,5,0,1,2,3,4};
//    auto iter = find_last_elem(numbers,0);
//
//    //print_through_iterator(iter,numbers.cend());
//
//    list<int> List;
//    copy_elem(numbers,List,3,7);
//    print_through_iterator(List.cbegin(),List.cend());
//
//
//}

//int main(){
//
//    iostream_iterator_to_file("./file/primer/10.33_in","./file/primer/10.33_out1","./file/primer/10.33_out2");
//    return 0;
//}

//int main(){
//    iostream_iterator_unique("./file/primer/10.30");
//    return 0;
//}

//int main(){
//
//    iostream_iterator("./file/primer/10.30");
//
//    return 0;
//}


//int main(){
//
//    vector<string> vec;
//    istream_iterator_vec(vec,"./file/primer/10.29");
////    ifstream file("./file/data");
////
////    string str;
////    if(file){
////        while(file >> str){
////            cout << str;
////        }
////    }
//
//    print_vector(vec);
//
//    return 0;
//}


//int main(){
//
//   ////iostream_iterator
//   istream_iterator<int> in(cin),eof;
//   cout << accumulate(in,eof,0);
//
//
//}

//List
//int main(){
//    List<int> list;
//    list.insert_node(1);
//#ifdef __DEBUG__
//    print_list(list); cout << endl;
//#endif
//    list.delete_node(1);
//    list.insert_node(0);
//    list.insert_node(2);
//    ListNode<int> *node = list.get_node(0);
//    list.delete_node(node);
//    node = list.get_node(2);
//    list.delete_node(node);
//    list.insert_node(3);
//    list.insert_node(4);
//    list.insert_node(5);
//    list.insert_node(6);
//
//    node = list.get_node(4);
//    list.delete_node(node);
//    list.insert_node(7);
//    list.insert_node(8);
//
//    node = list.get_node(3);
//    list.delete_node(node);
//    list.delete_node(8);
//    list.insert_node(9);
//
//#ifdef __DEBUG__
//    print_list(list); cout <<endl;
//#endif
//    return 0;
//}


//print_one_to_n
//int main(){
//    int _case = -1;
//    //print_one_to_n(_case); cout << endl;
//    print_one_to_n_1(_case); cout << endl;
//
//
//    _case = 2;
//    //print_one_to_n(_case); cout << endl;
//    print_one_to_n_1(_case); cout << endl;
//
//    _case = 5;
//    //print_one_to_n(_case);
//    print_one_to_n_1(_case); cout << endl;
//}


//pow
//int main(){
//    double base=0.0,ex=0;
//    //cout << POW(base,ex) << endl;
//
//    base = -4,ex= -2;
//    cout << POW(base,ex) << endl;
//
//    base = 2.3,ex=9;
//    cout << setprecision(20) << POW(base,ex) << endl;
//    return 0;
//}


////number_of_ones
//int main(){
//    int num = -2; //负数在计算机当中存的是补码
//    cout << number_of_ones(num) << endl;
//    cout << number_of_ones_2(num) <<endl;
//
//    num = -1;
//    cout << number_of_ones(num) << endl;
//    cout << number_of_ones_2(num) <<endl;
//
//    num = 3;
//    cout << number_of_ones(num) << endl;
//    cout << number_of_ones_2(num) <<endl;
//
//}

////rotate_array
//int main(){
//    vector<int> case1 = {1,2,3,4,5,6};
//    cout << rotate_min(case1) <<endl;
//
//    vector<int> case2 = {2,3,4,5,6,1};
//    cout << rotate_min(case2) << endl;
//
//    vector<int> case3 = {1,1,1,0,1};
//    cout << rotate_min(case3) << endl;
//
//    vector<int> case4 = {4,5,6,1,2,3};
//    cout << rotate_min(case4) << endl;
//
//    vector<int> case5 = {3,4,3,3,3,3,3,3,3,3,3,3,4,1,2};
//    cout << rotate_min(case4) << endl;
//
//    vector<int> case6 = {3,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2};
//    cout << rotate_min(case6) << endl;
//
//
//    return 0;
//}

////quick sort
//int main(){
//
//
//    vector<int> case1={1,2,3,4,5,6,7,8};
//    QuickSort<int> instance;
//    instance.sort(case1);
//    print_vector(case1);
//
//    vector<int> case2={8,7,6,5,4,3,2,1};
//    instance.sort(case2);
//    print_vector(case2);
//
//    vector<int> case3 = {1,4,2,8,7,3,6,5};
//    instance.sort(case3);
//    print_vector(case3);
//    return 0;
//}

//int main(){
//    Quene<int> Q;
//    cout << Q.is_empty();
//    Q.push(1);
//    int a= 3;
//    Q.push(3);
//    cout << Q.front();
//    Q.pop();
//    cout << Q.front();
//    Q.pop();
//
//    cout << Q.is_empty();
//
//    return 0;
//}

/*
int main() {
    char str[] = "10.18.0.1";
    struct in_addr ip4;
    bzero((void *)&ip4,sizeof(ip4));
    Inet_PtoN(AF_INET,str,(void*)&ip4);
    for(int i=0;i<4;++i){
        printf("%x",((char*)&ip4)[i]);
    }
    return 0;
}*/

//4
//int main(){
//
//    Solution4 instance;
//    double medium = 0;
//    //case 1
//    vector<int> case1_1 = {1,3};
//    vector<int> case1_2 = {2};
//    medium = instance.findMedianSortedArrays(case1_1,case1_2);
//    cout << medium << endl;
//
//    vector <int> case2_1 = {1,2};
//    vector <int> case2_2 = {3,4};
//    medium = instance.findMedianSortedArrays(case2_1,case2_2);
//    cout << medium << endl;
//
//}

//int main(){
//    cout << "heating macbook pro...\n";
//    unsigned long long times = 0;
//    while(1){
//        cout << "heating " << ++times <<"time(s)" << endl;
//        usleep(5);
//        if(times % 50 == 0){
//            system("clear");
//        }
//    }
//
//    return 0;
//}


//rebulid binary tree
//int main(){
//
//    class rebuild_binary_tree<int> instance;
//    vector<int> case1_pre = {1,2,4,7,3,5,6,8};
//    vector<int> case1_in = {4,7,2,1,5,3,8,6};
//
//    binary_tree_node<int> * root_1 = instance.RBT(case1_pre,case1_in,0,case1_pre.size()-1,0,case1_in.size()-1);
//
//    cout << "pre_traverse:";
//    instance.pre_traverse(root_1);
//    cout << endl;
//
//    cout << "in_traverse:";
//    instance.in_traverse(root_1);
//    cout << endl;
//
//    cout << "post_traverse:";
//    instance.post_traverse(root_1);
//    cout << endl;
//
//    cout << "level_traverse:";
//    instance.level_traverse(root_1);
//    cout << endl;
//
//    instance.destory_binary_tree(root_1);
//
//    vector<int> case2_pre={1,2,3,4,5,6,7,8};
//    vector<int> case2_in = {8,7,6,5,4,3,2,1};
//
//    binary_tree_node<int> * root_2 = instance.RBT(case2_pre,case2_in,0,case2_pre.size()-1,0,case2_in.size()-1);
//
//    cout << "pre_traverse:";
//    instance.pre_traverse(root_2);
//    cout << endl;
//
//    cout << "in_traverse:";
//    instance.in_traverse(root_2);
//    cout << endl;
//
//    cout << "post_traverse:";
//    instance.post_traverse(root_2);
//    cout << endl;
//
//    cout << "level_traverse:";
//    instance.level_traverse(root_2);
//    cout << endl;
//
//    instance.destory_binary_tree(root_2);
//
//
//    vector<int> case3_pre={1,2,4,8,9,5,10,11,3,6,7};
//    vector<int> case3_in = {8,4,9,2,10,5,11,1,6,3,7};
//
//    binary_tree_node<int> * root_3 = instance.RBT(case3_pre,case3_in,0,case3_pre.size()-1,0,case3_in.size()-1);
//
//    cout << "pre_traverse:";
//    instance.pre_traverse(root_3);
//    cout << endl;
//
//    cout << "in_traverse:";
//    instance.in_traverse(root_3);
//    cout << endl;
//
//    cout << "post_traverse:";
//    instance.post_traverse(root_3);
//    cout << endl;
//
//    cout << "level_traverse:";
//    instance.level_traverse(root_3);
//    cout << endl;
//
//    instance.destory_binary_tree(root_3);
//
//
//    return 0;
//}
//
//int main(){
//    const int a = 13;
//    const int *p = &a;
//    int b = 3;
//
//    int const * q = &b;
//    cout << (unsigned long long)q << endl;
//
//
//    q = &a;
//    cout << (unsigned long long)q << endl;
//
//    const int * k = &b;
//    cout << (unsigned long long)k << endl;
//
//    k = &a;
//    cout << (unsigned long long)k << endl;
//
//    int * const j = &b;
//    int c = 10;
//
//    class Test{
//    public:
//        int get_value()const{
//            return val;
//        }
//
//    private:
//        int val;
//    };
//
//    const Test * ca = new Test;
//    cout << ca->get_value() <<endl;
//}




