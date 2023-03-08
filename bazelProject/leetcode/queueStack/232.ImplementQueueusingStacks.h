#include <stack>
using namespace std;

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        adjust();
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
        adjust();
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }

private:
    stack<int> s1,s2;

    void adjust() {
        if(empty() || !s2.empty()) {
            return;
        }

        int tmp;
        while(!s1.empty()) {
            tmp = s1.top();
            s1.pop();
            s2.push(tmp);
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */