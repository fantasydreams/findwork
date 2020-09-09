//
// Created by Sharwen on 2020/2/12.
//

#include "../../header/test.h"

int binary_serch(vector<int> & num,int left,int right,int key){
    if(left > right) return-1;

    while(left <= right){
        int mid = (left + right) / 2;
        if(num[mid] < key)left = mid + 1;
        else if(num[mid] > key) right = mid - 1;
        else return mid;
    }
    return -1;
}

int find(vector<int> array, int key ){
    if(array.size() == 0) return -1;
    if(array[0] < array[array.size()-1]){
        return binary_serch(array,0,array.size()-1,key);
    }

    int left = 0,right = array.size()-1;
    int mid;
    while(left < right && left != right - 1) {
        mid = (left + right) / 2;
        if (array[left] < array[mid]) left = mid;
        else if (array[mid] < array[left]) right = mid;
    }

    if(array[mid] <= key && array[array.size()-1] >= key) return binary_serch(array,mid,array.size()-1,key);
    return binary_serch(array,0,mid-1,key);
}

void test_alloc(){
    int *p = (int*)malloc(sizeof(int) * 10);
    cout << p <<endl;
    int *q = (int *)realloc(p,sizeof(int) * 20);
    cout << q << endl;
}

void const_call(const int a){
    std::cout << a <<std::endl;
}

void const_call(const int * val){ // 顶层const可以区分重载，底层不行
    std::cout << "const" << std::endl;
}

void const_call(int * val){
    std::cout << "const" << std::endl;
}

Foo Foo::sorted() && {
    std::sort(data.begin(), data.end());
    std::cout << "&&" << std::endl; // debug
    return *this;
}

Foo Foo::sorted() const &
{
//    Foo ret(*this);
//    sort(ret.data.begin(), ret.data.end());
//    return ret;
//    std::cout << "const &" << std::endl; // debug
//     Foo ret(*this);
//     ret.sorted(); // Exercise 13.56
//     return ret;
    return Foo(*this).sorted(); // Exercise 13.57   //构造函数返回的一定是右值，所以这里调用右值版本
}



void test_ref(int & a){
    std::cout << a;
}


void test_shared(){
    shared_ptr<int> p = make_shared<int>(0);
    cout << p.use_count() << endl;  //引用计数为1

    shared_ptr<int> q = p;  //operator = 增加引用计数，为2,p,q指向同一个shared对象，引用计数相同
    //operator=可以先递增右侧对象的引用计数，然后递减左侧对象的引用计数，然后再进行成员拷贝
    cout << p.use_count() << endl;
    cout << q.use_count() << endl;


    //对于空的shared_ptr operator不会增加其引用计数
    shared_ptr<int> null;
    shared_ptr<int> null2 = null;
    cout << "null_shared_ptr:" <<null.use_count();
}


std::unique_ptr<int> unique_ptr_test(int p){
    std::unique_ptr<int> up(new int (p));
    return up;
}

//void shared_ptr_fun(std::shared_ptr<int> &p){
//    p = make_shared<int>();
//
//}
//
//
//void shared_ptr_text(){
//    std::shared_ptr<int> p;
//    shared_ptr_fun(p);
//    cout << p.use_count();
//}

//测试map通过第二个关键测进排序 ::  测试结果，map自动字典序，没有sort对应的模板对map进行排序，如果要排序可以通过把map拷贝到vector<pair<T1,T2>>中然后进行排序

//template <class T1,class T2>
//bool _compare(const std::pair<const T1,T2> &p1,const std::pair<const T1,T2> & p2){
//    return p1.second < p2.second;
//}
//
//template <class T1,class T2>
//void map_sort_by_maptype(std::map<T1,T2> Map,std::vector<std::pair<T1,T2>> &res){
//    for(auto val : Map){
//        res.push_back(std::pair<T1,T2>(val.first,val.second));
//    }
//    sort(res.begin(),res.end(),_compare);
//}
bool _compare(const std::pair<const std::string,int> &p1,const std::pair<const std::string,int> & p2){
    return p1.second < p2.second;
}


void map_sort_by_maptype(std::map<std::string,int> Map,std::vector<std::pair<std::string,int>> &res){
    for(auto val : Map){
        res.push_back(std::pair<std::string,int>(val.first,val.second));
    }
    sort(res.begin(),res.end(),_compare);
}


