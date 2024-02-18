#include "224.BasicCalculator.h"
#include <cmath>
#include <queue>
#include <stack>

int64_t GetNextNumber(const std::string& str, int& idx) {
    int64_t number = 0;
    while(idx < str.size() && str[idx] == ' ') {
        ++idx;
    }

    while(idx < str.size() && str[idx] >= '0' && str[idx] <= '9') {
        number = number * 10 + str[idx] - '0';
        ++idx;
    }
    // printf("1111; %d\n", idx);
    return number;
}


int calculate(string s) {
    std::deque<int64_t> stPara;
    std::deque<char> stOp;

    int idx = 0;

    bool bOther = false;
    while(idx < s.size()) {
        if(s[idx] == ' ') {
            ++idx;
            continue;
        }

        if(s[idx] == '(' || s[idx] == ')' || s[idx] == '+' || s[idx] == '-') {
            if(s[idx] == '(') {
                bOther = true;
                stOp.push_back('(');
                ++idx;
                stPara.push_back(GetNextNumber(s, idx));
            }else if(s[idx] == ')') {
                bOther = true;
                ++idx;
                char op = stOp.back(); stOp.pop_back();
                stack<int64_t> stPara1; stPara1.push(stPara.back()); stPara.pop_back();
                stack<char> stOP1;
                while(op != '(') {
                    stOP1.push(op);
                    stPara1.push(stPara.back()); stPara.pop_back();
                    op = stOp.back(); stOp.pop_back();
                }

                while(!stOP1.empty()) {
                    op = stOP1.top(); stOP1.pop();
                    int64_t a1 = stPara1.top(); stPara1.pop();
                    int64_t a2 = stPara1.top(); stPara1.pop();
                    if(op == '+') {
                        stPara1.push(a1 + a2);
                    }else {
                        stPara1.push(a1 - a2);
                    }
                }

                stPara.push_back(stPara1.top());
            }else {
                if(bOther == false) {
                    stPara.push_back(0);
                    bOther = true;
                }
                stOp.push_back(s[idx++]);
                while(idx < s.size() && s[idx] == ' ') {
                    ++idx;
                    continue;
                }
                if(idx >= s.size()) {
                    break;
                }
                if(s[idx] == '(' || s[idx] == ')') {
                    bOther = false;
                    continue;
                }

                stPara.push_back(GetNextNumber(s, idx));
            }
        }else {
            bOther = true;
            stPara.push_back(GetNextNumber(s, idx));
        }
    }

    while(!stOp.empty()) {
        int64_t a1 = stPara.front(); stPara.pop_front();
        int64_t a2 = stPara.front(); stPara.pop_front();
        char op = stOp.front();stOp.pop_front();
        if(op == '+') {
            stPara.push_front(a1 + a2);
        }else {
            stPara.push_front(a1 - a2);
        }
    }

    return stPara.empty() ? 0 : stPara.front();
}


int calculate1(string s) {
    std::stack<int> st;
    st.push(1);
    int sign = 1;

    int ret = 0;
    int i = 0; 
    while(i < s.size()) {
        if(s[i] == ' ') {
            ++i;
            continue;
        }

        if(s[i] =='+') {
            sign = st.top();
            ++i;
        }else if(s[i] == '-') {
            sign = -st.top();
            ++i;
        }else if(s[i] == '(') {
            st.push(sign);
            ++i;
        }else if(s[i] == ')') {
            st.pop();
            ++i;
        }else {
            ret += sign * GetNextNumber(s, i);
        }
    }

    return ret;
}


int calculate2(string s) {
    int ans = 0;
    std::stack<int> st; st.push(1);
    int sign = 1, idx = 0;;
    while(idx < s.size()) {
        if(s[idx] == ' ') {
            ++idx;
            continue;
        }

        if(s[idx] == '-') {
            sign = -st.top();
            ++idx;
        }else if(s[idx] == '+') {
            sign = st.top();
            ++idx;
        }else if(s[idx] == '(') {
            st.push(sign);
            ++idx;
        }else if(s[idx] == ')') {
            st.pop();
            ++idx;
        }else {
            ans += sign * GetNextNumber(s, idx);
        }
    }


    return ans;
}