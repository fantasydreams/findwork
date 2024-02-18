#include <stack>
#include <cmath>

class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        originSt.push(val);
        if(!minSt.empty()) {
            minSt.push(std::min(minSt.top(), val));
        }else {
            minSt.push(val);
        }
    }
    
    void pop() {
        originSt.pop();
        minSt.pop();
    }
    
    int top() {
        return originSt.top();
    }
    
    int getMin() {
        return minSt.top();
    }

private:
    std::stack<int> originSt, minSt;
};


class MinStack1 {
public:
    MinStack1() {
        
    }
    
    void push(int val) {
       if(st.empty()) {
            st.push({val, val});
       }else {
            st.push({val, std::min(val, st.top().second)});
       }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }

private:
    std::stack<std::pair<int, int>> st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


 class MinStack2 {
public:
    MinStack2() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push({val, val});
        }else {
            st.push({val, std::min(st.top().second, val)});
        }
    }
    
    void pop() {
        st.pop();    
    }
    
    int top() {
        return st.top().first;    
    }
    
    int getMin() {
        return st.top().second;    
    }

private:
    std::stack<std::pair<int, int> > st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


class MinStack3 {
public:
    MinStack3() {

    }
    
    void push(int val) {
        st.push(val);
        min.push(min.empty() ? val : std::min(val, min.top()));
    }
    
    void pop() {
        st.pop();
        min.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
    }

private:
    std::stack<int> min;
    std::stack<int> st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */