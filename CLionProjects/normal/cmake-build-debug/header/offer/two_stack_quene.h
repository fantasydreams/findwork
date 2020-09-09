//
// Created by Sharwen on 2020/2/1.
//
#include<stack>
#include<exception>
using namespace std;
#ifndef C___TWO_STACK_QUENE_H
#define C___TWO_STACK_QUENE_H

template<class T> class Quene{
public:
    bool is_empty();
    const T & front();
    void pop();
    void push(const int & val);

private:
    stack<T> s1;
    stack<T> s2;
};

template <class T> bool Quene<T>::is_empty() {
    if(s1.empty() && s2.empty()) {
        return true;
    }else{
        return false;
    }
}

template<class T> const T & Quene<T>::front() { //需要用户自行判断队列是否为空，否则可能导致异常
    if(!s2.empty()){
        return s2.top();
    }else{
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        return s2.top();
    }
}

template <class T> void Quene<T>::pop() {
    if(!s2.empty()){
        s2.pop();
    }
    else{
        if(!s1.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
    }
}

template<class T> void Quene<T>::push(const int &val) {
    s1.push(val);
}

#endif //C___TWO_STACK_QUENE_H
