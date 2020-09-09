//
// Created by Sharwen on 2020/2/12.
//

#ifndef C___TEST_H
#define C___TEST_H
#include "project.h"
#include "tools.h"


template<class A,class B>class base{
public:
    base(A a,B b):m_a(a),m_b(b){};

private:
    A m_a;
    B m_b;
};


template<class A,class B,class C>class derive:base<A,B>{
public:

};

void test_alloc();

template<class T>
bool my_less1(T& a, T& b){
    return (a < b);
};



inline size_t __size(int size){
    return size;
}

class static_inline{
public:
    static size_t get_size(int a){
        return __size(a);
    }
    int get()const{
        return val;
    }
private:
    int val;
};

//template <class T> int compare(const T&, const T&);


void const_call(const int a); //可将非const传递给const，因为这里只是进行拷贝操作，不是引用，因此顶层const是不能区分重载的
void const_call(const int * val);
void const_call(int * val);

template<typename T, unsigned N> constexpr
unsigned size(const T (&arr)[N])
{
    return N;
}

template <typename T,unsigned N, unsigned M>constexpr
bool my_compare(const T(&arr)[N],const T (&brr)[M]){
    return strcmp(arr,brr);
}

template <typename T> T calc(T, int){}
template <typename T> T fcn(T, T){};


template<class T>
void print(const T & arr){
    for(auto & val : arr){
        std::cout << val << std::endl;
    }
}

template <class A,class B>
struct my_less{
public:

    bool operator()(const A &a,const B &b){
        return a < b;
    }
    ~my_less()= default;
};

class ostream_test{
public:
    ostream_test(int val):data(val){};
    ~ostream_test() = default;
    void print(std::ostream & o){
        o << data;
    }
private:
    int data;
};

//int main(){
//    ostream_test a(1);
//    a.print(cout);  //输入输出流可以当作参数传入类中，只有进行<< , >>运算符重载的时候，才需要将重载的函数设置为友元
//    return 0;
//}

//A a;
//int A::*ip;   //给这个类增加类指针
//ip = &A::data;
//cout << a.*ip << endl;

class A{
public:
    int data;
};


class Foo
{
public:
    Foo sorted() && ;
    Foo sorted() const &;
private:
    std::vector<int> data;
};


//Intvec v2;
//v2 = Intvec(12); 这个右值临时对象会在语句复制完后进行析构
//cout << "endl" << endl;
//
//v2 = Intvec(); //这个会返回一个临时对象，
//cout << "endl2" << endl;


class Intvec
{
public:
    explicit Intvec(size_t num = 0)
            : m_size(num), m_data(new int[m_size])
    {
        log("constructor");
    }

    ~Intvec()
    {
        log("destructor");
        if (m_data) {
            delete[] m_data;
            m_data = 0;
        }
    }

    Intvec(const Intvec& other)
            : m_size(other.m_size), m_data(new int[m_size])
    {
        log("copy constructor");
        for (size_t i = 0; i < m_size; ++i)
            m_data[i] = other.m_data[i];
    }

    Intvec& operator=(const Intvec& other)
    {
        log("copy assignment operator");
        Intvec tmp(other);
        std::swap(m_size, tmp.m_size);
        std::swap(m_data, tmp.m_data);
        return *this;
    }
private:
    void log(const char* msg)
    {
        std::cout << "[" << this << "] " << msg << "\n";
    }

    size_t m_size;
    int* m_data;
};


class test{
public:
    test(){std::cout << "defalut constructer...\n";};
    test(const test & t){
        std::cout << "copy constructer...\n";
        test(); //如果在构造函数的初始列表里面调用构造函数，会产生一个类的临时对象，从而引发构造和析构，一定要注意
    }

    test(const test &m,const test &n):test(){ //放在初始化列表后面是不会产生临时对象
        std::cout << "copy constructer 2 para ...\n";
    }
    ~test(){
        std::cout << "deconstructer...\n";
    }
};

void test_shared();

std::unique_ptr<int> unique_ptr_test(int p);

void shared_ptr_text();

void map_sort_by_maptype(std::map<std::string,int> Map,std::vector<std::pair<std::string,int>> &res);

#endif //C___TEST_H
