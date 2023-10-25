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