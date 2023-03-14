#include "227.BasicCalculatorII.h"
#include <vector>
#include <stack>

using namespace std;

inline bool isOpsub(const char & ch) {
    return ch =='+' || ch == '-';
}

inline bool isOpPro(const char & ch) {
    return ch =='/' || ch =='*';
}

int nextNum(const string & s, int & idx) {
    int tmp = 0;
    while(idx < s.size()) {
        if(s[idx] == ' ') {
            ++idx;
            continue;
        }

        if(isOpsub(s[idx] || isOpPro(s[idx]))) {
            --idx;
            break;
        }

        tmp = tmp * 10 + s[idx++] - '0';
    }
    return tmp;
}

int calculate(string s) {
    int tmp = 0, res, n1, n2;
    stack<int> nums;
    stack<char>op;
    for(int i = 0; i <= s.size(); ++i) {
        if(i == s.size()) {
            nums.push(tmp);
            break;
        }
        if(s[i] == ' ') {
            continue;
        }
        if(isOpsub(s[i])) {
            op.push(s[i]);
            nums.push(tmp);
            tmp=0;
        }else if(isOpPro(s[i])) {
            char tmpch = s[i];
            n1 = tmp;
            ++i;
            n2 = nextNum(s, i);
            if(tmpch == '/') {
                res = n1 / n2;
            }else {
                res = n1 * n2;
            }
            nums.push(res);
            tmp=0;
        }else {
            tmp = tmp * 10 + s[i] - '0';
        }
    }

    while(!op.empty()) {
        char ch = op.top(); op.pop();
        n2 = nums.top();nums.pop();
        n1 = nums.top();nums.pop();
        if(ch == '+') {
            res = n1 + n2;
        }else {
            res = n1 - n1;
        }
        nums.push(res);
    }

    return nums.top();
}