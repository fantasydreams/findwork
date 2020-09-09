//
// Created by Sharwen on 2020/2/22.
//

#ifndef C___MIN_STACK_H
#define C___MIN_STACK_H


#include <stack>

template<class T>
class min_stack{
public:
    min_stack(){}
    void push(const T &val){
        m_s.push(val);
        if(a_s.empty()){
            a_s.push(val);
        }else{
            a_s.push(val > a_s.top() ? a_s.top():val);
        }
    }

    T top(){
        return m_s.top();
    }

    void pop(){
        m_s.pop();
        a_s.pop();
    }

    T get_min(){
        return a_s.top();
    }

    bool empty(){
        return m_s.empty();
    }

private:
    std::stack<T> m_s,a_s;
};

#endif //C___MIN_STACK_H
