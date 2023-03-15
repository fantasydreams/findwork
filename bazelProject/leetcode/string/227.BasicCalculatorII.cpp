#include "227.BasicCalculatorII.h"
#include <vector>
#include <stack>
#include <locale>

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

        if(isOpsub(s[idx]) || isOpPro(s[idx])) {
            break;
        }

        tmp = tmp * 10 + s[idx++] - '0';
    }
    return tmp;
}

int calculate(string s) {
    int64_t tmp = 0, res, n1, n2;
    deque<int64_t> nums;
    deque<char>op;
    for(int i = 0; i <= s.size(); ++i) {
        if(i == s.size()) {
            nums.push_back(tmp);
            break;
        }
        if(s[i] == ' ') {
            continue;
        }
        if(isOpsub(s[i])) {
            op.push_back(s[i]);
            nums.push_back(tmp);
            tmp=0;
        }else if(isOpPro(s[i])) {
            char tmpch = s[i];
            n1 = tmp;
            ++i;
            n2 = nextNum(s, i);
            --i;
            if(tmpch == '/') {
                res = n1 / n2;
            }else {
                res = n1 * n2;
            }
            tmp=res;
        }else {
            tmp = tmp * 10 + s[i] - '0';
        }
    }

    while(!op.empty()) {
        char ch = op.front(); op.pop_front();
        n1 = nums.front();nums.pop_front();
        n2 = nums.front();nums.pop_front();
        if(ch == '+') {
            res = n1 + n2;
        }else {
            res = n1 - n2;
        }
        nums.push_front(res);
    }

    return nums.front();
}


int64_t getNext(const std::string & s, int & idx) {
    int64_t num = 0;
    for(;idx < s.size() && isdigit(s[idx]); ++idx) {
        num = 10 * num + s[idx] - '0';
    }

    return num;
}

int calculate1(string s) {
    char op = '+';
    int64_t left = 0, right = 0, tmp;
    int i = 0;
    while(i < s.size()) {
        if(s[i] == ' ') {
            ++i;
            continue;
        }

        tmp = getNext(s, i);
        switch(op) {
            case '+':
                left += right;
                right = tmp;
                break;
            case '-':
                left += right;
                right = -tmp;
                break;
            case '*':
                right *= tmp;
                break;
            case '/':
                right /= tmp;
                break;
        }

        if(i < s.size()) {
            op = s[i++];
        }
    }

    return left + right;
}