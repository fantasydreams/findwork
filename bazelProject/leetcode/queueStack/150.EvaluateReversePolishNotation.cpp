#include "150.EvaluateReversePolishNotation.h"
#include <stack>
#include <string>

int evalRPN(vector<string>& tokens) {
    if(tokens.empty()) {
        return 0;
    }

    std::stack<int64_t> number;
    for(auto & str : tokens) {
        if(str == "+" || str == "-" || str == "/" || str == "*") {
            int64_t num2 = number.top(); number.pop();
            int64_t num1 = number.top(); number.pop();
            if(str == "+") {
                number.push(num1 + num2);
            }else if(str == "-") {
                number.push(num1 - num2);
            }else if(str == "*") {
                number.push(num1 * num2);
            }else {
                number.push(num1 / num2);
            }
        }else {
            number.push(stoi(str));
        }
    }

    return number.top();
}


int evalRPN1(vector<string>& tokens) {
    int ans = 0;
    if(tokens.empty()) {
        return ans;
    }

    std::stack<int64_t> st;
    for(const auto& token : tokens) {
        if(token == "+" || token == "-" || token == "*" || token == "/") {
            int64_t iNum2 = st.top(); st.pop();
            int64_t iNum1 = st.top(); st.pop();
            if(token == "+") {
                st.push(iNum1 + iNum2);
            }else if(token == "-") {
                st.push(iNum1 - iNum2);
            }else if(token == "*") {
                st.push(iNum1 * iNum2);
            }else {
                st.push(iNum1 / iNum2);
            }
        }else {
            st.push(atoi(token.c_str()));
        }
    }

    return st.top();
}