#include <queue>
using namespace std;

class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int tmp = q1.front();
        q1.pop();
        swap(q1,q2);
        return tmp;
    }
    
    int top() {
        while(q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int tmp = q1.front();
        q2.push(q1.front());
        q1.pop();
        swap(q1,q2);
        return tmp;
    }
    
    bool empty() {
        return q1.empty();
    }

private:
    queue<int> q1, q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


 class MyStack1 {
public:
    MyStack1() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int size = q.size(), tmp;
        while(size-- > 1) {
            tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        tmp = q.front();
        q.pop();
        return tmp;
    }
    
    int top() {
        int size = q.size(), tmp;
        while(size-- > 1) {
            tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        tmp = q.front();
        q.pop();
        q.push(tmp);
        return tmp;
    }
    
    bool empty() {
        return q.empty();
    }

private:
    queue<int> q;
};