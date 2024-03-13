#include "22.GenerateParentheses.h"
#include <string>

void generateParenthesis(int left, int right, std::string& sTmp, std::vector<std::string> &vecAns) {
    if(left == 0 && right == 0) {
        vecAns.push_back(sTmp);
        return;
    }

    if(left) {
        sTmp.push_back('(');
        generateParenthesis(left - 1, right, sTmp, vecAns);
        sTmp.pop_back();
    }

    if(left < right) {
        sTmp.push_back(')');
        generateParenthesis(left, right - 1, sTmp, vecAns);
        sTmp.pop_back();
    }
}


vector<string> generateParenthesis(int n) {
    std::string sTmp;
    std::vector<std::string> vecAns;
    generateParenthesis(n, n, sTmp, vecAns);
    return vecAns;
}