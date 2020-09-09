//
// Created by Sharwen on 2020/2/11.
//
#define __DEBUG__

#ifndef C___PRIMER_HEADER_H
#define C___PRIMER_HEADER_H
#include <vector>
#include <string>
#include <functional>
#include <list>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <deque>
#include <fstream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include "tools.h"



//14.1
class sale_data{
public:

    friend std::istream & operator >> (std::istream & cin,sale_data & );
    friend std::ostream & operator << (std::ostream & cout,const sale_data & );

    sale_data(int p = 0):price(p){}
    sale_data(const sale_data & s){price = s.price;}
    sale_data &operator=(const sale_data & s){price = s.price; return *this;}
    sale_data operator+(const sale_data & s) const {sale_data res(this->price + s.price); return res;}
private:
    int price;
};


//13.39
class strVec{
public:
    strVec():_first_elem(nullptr),_first_free(nullptr),_cap(nullptr){};
    strVec(const strVec &);
    strVec(std::initializer_list<std::string> );
    strVec &operator=(const strVec &);
    ~strVec(){free();}
    void push_back(const std::string &);
    size_t size() const {return _first_free-_first_elem;}
    size_t capacity() const {return _cap - _first_free;}
    std::string *begin(){return _first_elem;}
    std::string *begin() const{return _first_free;}
    std::string *end(){return _first_elem;}
    std::string *end()const {return _first_free;}


private:

    void check_n_allocator(){
        if(size() == capacity()){
            reallocate();
        }
    }
    void reallocate();
    std::pair<std::string *,std::string *> alloc_n_copy(const std::string *,const std::string *);
    void free();


    std::allocator<std::string> _alloc;
    std::string * _first_elem;
    std::string * _first_free;
    std::string * _cap;
};

//13.29
class hasPtr{
public:
    hasPtr(std::string s,int i){
        _p_str = new std::string(s);
        _i = i;
    }

    hasPtr(const hasPtr & o){
        _p_str = new std::string(*o._p_str);
        _i = o._i;
    }

    bool operator < (const hasPtr & co) const{
        return *_p_str < *(co._p_str);
    }

    friend void swap(hasPtr & o1,hasPtr & o2){
        std::cout << "swap has been called!";
        std::swap(o1._p_str,o2._p_str);
        std::swap(o1._i,o2._i);
    }

    hasPtr & operator = (hasPtr o){
        swap(*this,o);
        return *this;
    }

    ~hasPtr(){
        delete _p_str;
    }

private:
    std::string *_p_str;
    int _i;
};


//13.27

template <class _T>
class my_shared_ptr{
public:
    typedef _T element_type;
    my_shared_ptr();
    my_shared_ptr(element_type *);
    my_shared_ptr(const my_shared_ptr<element_type> &p);
    ~my_shared_ptr();
    my_shared_ptr & operator=(const my_shared_ptr<element_type> &co);
    size_t use_count();
private:

    void incre_use(const my_shared_ptr<element_type> & o);
    void decre_use(const my_shared_ptr<element_type> & o);
    element_type * _val;
    size_t *_p_use_count;
};


template<class _T> size_t my_shared_ptr<_T>::use_count(){
    return *_p_use_count;
}

template<class _T>my_shared_ptr<_T>::~my_shared_ptr(){
    decre_use(*this);
}

template <class _T>my_shared_ptr<_T> & my_shared_ptr<_T>
        :: operator=(const my_shared_ptr<element_type>& co){
    incre(co);
    decre(*this);
    this->val = co._val;
    this->_p_use_count = co._p_use_count;

    return *this;
}

template <class _T> void my_shared_ptr<_T>::incre_use(const my_shared_ptr<_T> & o){
    ++(*o._p_use_count);
}

template <class _T>void my_shared_ptr<_T>::decre_use(const my_shared_ptr<_T> & o){
    if(*o._p_use_count == 0 || --(*o._p_use_count) == 0){
        delete _val;
        delete _p_use_count;
    }
}

template <class _T> my_shared_ptr<_T>::my_shared_ptr(){
    _p_use_count = new size_t(0);
    _val = nullptr;
}

template <class _T> my_shared_ptr<_T>::my_shared_ptr(_T * p){
    if(p){
       _val = p;
       _p_use_count = new size_t(0);
       incre_use(*this);
    }
}

template <class _T> my_shared_ptr<_T>::my_shared_ptr(const my_shared_ptr<_T> &p){
    if(*p._p_use_count){
        this->_val = p._val;
        this->_p_use_count = p._p_use_count;

        incre_use(*this);
    }else{
//        _val = nullptr;
//        _p_use_count = new size_t(0);
        my_shared_ptr();
    }
}


class QueryResult{
public:

    friend void Query_res_print(std::ostream & out,const QueryResult & qr);
    QueryResult(std::string q_w,size_t c,std::shared_ptr<std::vector<std::string>> t,std::shared_ptr<std::set<size_t>> l_n):
    _query_word(q_w),_count(c),_text(t),_line_number(l_n){};
private:
    size_t _count;
    std::string _query_word;
    std::shared_ptr<std::vector<std::string>> _text;
    std::shared_ptr<std::set<size_t>> _line_number;
};

//12.30
class TextQuery{
public:
    TextQuery(std::string file_name);
    QueryResult query(std::string word);

private:
    std::shared_ptr<std::vector<std::string>> _file;
    std::map<std::string,std::pair<size_t,std::shared_ptr<std::set<size_t>>>> _word;
};


//12.27
#ifdef __DEBUG__
class Text;

void print_vector(const Text & t);
void print_word(const Text & t);
#endif
class Text{
public:
    Text();
    Text(std::string file_name);
    void set_file(std::string file_name){f_n = file_name;};
    void query(std::string);

#ifdef __DEBUG__
    friend void print_vector(const Text & t);
    friend void print_word(const Text & t);
#endif

private:
    std::string f_n;
    std::map<std::string,std::pair<size_t,std::set<size_t>>> word;
    std::vector<std::string> text;
};


//12.24
void is_string();

//12.23
char * concate_charstring(const char *s1,const char * s2);
std::string concate_string(const std::string &s1,const std::string &s2);

//12.16
void test_unique_copy();

//12.10

void shared_ptr_process(std::shared_ptr<int> p);

//12,7
std::shared_ptr<std::vector<int>> new_int_vec_shared_ptr();

//12,6
std::vector<int> * new_int_vec();

//12.2
class strBolb{
public:
    using size_type = std::vector<std::string>::size_type;
    strBolb();
    strBolb(std::initializer_list<std::string> il);
    size_type size() const {return data->size();};
    bool empty(){return data->empty();};
    bool empty()const{ return  data->empty();};
    void push_back(const std::string & val){data->push_back(val);};
    void pop_back();
    std::string &front();
    std::string front()const;
    std::string &back();
    std::string back() const;

private:
    std::shared_ptr<std::vector<std::string>> data;
};

//11.38
void exchange_text_unorder_map(std::string textname,std::string rule);

//11.33
void exchange_text_map(std::string textname,std::string rule);


//11.32
template<class T1,class T2>
void print_multimap_by_dict_order(const std::multimap<T1,T2> &MP){
    std::map<T1,std::multiset<T2>> ordered_mp;
    for(const auto & val : MP){
        ordered_mp[val.first].insert(val.second);
    }

    for(const auto & val : ordered_mp){
        std::cout <<val.first << std::endl;
        for(const auto & Pair : val.second){
            std::cout<<"    " << Pair << std::endl;
        }
        std::cout << std::endl;
    }

}

//11.31
template<class T1,class T2>
void erase_multimap_by_key(std::multimap<T1,T2> &multi_Map,T1 key){ //默认multimap按照关键字字典序列，但是MAP_TYPE不是按照字典序列
    auto pos = multi_Map.equal_range(key);
    multi_Map.erase(pos.first,pos.second);
}

//11.13
void make_pair_string_int(std::vector<std::pair<std::string,int>> &vec);

//11.3-4
void count_words(const std::string & filename,
        std::map<std::string,unsigned int>& dict,const std::set<std::string> &exclude);

//10.42
void list_unique(std::list<std::string> &text,std::string filename);

//10.37
template<class T>
void copy_elem(const std::vector<T> &vec,std::list<T> & List, unsigned int left, unsigned int right){
    if(left >= right || right > vec.size()) return;
    std::copy(vec.cbegin() + left,vec.cbegin() + right,std::inserter(List,List.begin()));
}

//10.36
auto find_last_elem(std::vector<int> numbers,int val)->std::vector<int>::const_iterator;

//10.35
template <class T>
void reverse_print_vector_common_iterater(const std::vector<T> & vec){
    std::ostream_iterator<T> out(std::cout," ");
    for(auto iter = vec.cend();iter >= vec.begin();--iter){
        *out++ = *iter;
    }
}

//10.34
//template <class T>
//void reverse_print_vector(const std::vector<T> & vec);
template <class T>
void reverse_print_vector(const std::vector<T> & vec){
    std::ostream_iterator<T> out(std::cout," ");
    for(auto criter = vec.crbegin();criter != vec.crend();++criter){
        *out++ = *criter;
    }
}

//10.33
void iostream_iterator_to_file(const std::string & in_filename,const std::string &out_file_name1,const std::string &out_file_name2);

//10.31

void iostream_iterator_unique(const std::string & filename);

//10.30
void iostream_iterator(const std::string &filename);

//10.29
void istream_iterator_vec(std::vector<std::string>& vec,std::string filename);

//10.28
void three_inserter(const std::vector<int> &numbers);

//10.27

void unique_copy_v_to_l(std::vector<std::string> text, std::list<std::string> &List);

//10.24
std::string my_find_if(const std::vector<std::string> & text, const std::string & str);

//10.23
unsigned long long count_words_overlength(const std::vector<std::string> & text, unsigned int len);

#endif //C___PRIMER_HEADER_H
