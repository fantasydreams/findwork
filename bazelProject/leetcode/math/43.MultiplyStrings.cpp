#include "43.MultiplyStrings.h"
#include <stdlib.h>
#include <cctype>
#include <string>


void addVec(std::vector<int>& res, const std::vector<int>& beAdd) {
    int i = 0;
    int carry = 0, sum = 0;
    while(i < res.size() && i < beAdd.size()) {
        sum = res[i] + beAdd[i] + carry;
        res[i] = sum % 10;
        carry = sum / 10;
        ++i;
    }

    while(i < beAdd.size()) {
        sum = beAdd[i] + carry;
        res.push_back(sum % 10);
        carry = sum / 10;
        ++i;
    }

    if(carry) {
        res.push_back(carry);
    }
}

string multiply(string num1, string num2) {

    std::vector<int> n1;
    std::vector<int> n2;

    for(int i = num1.size() - 1; i >= 0; --i) {
        if(std::isdigit(num1[i])) {
            n1.push_back(num1[i] - '0');
        }else {
            return "0";
        }
    }

    for(int i = num2.size() - 1; i >= 0; --i) {
        if(std::isdigit(num2[i])) {
            n2.push_back(num2[i] - '0');
        }else {
            return "0";
        }
    }

    // 把前向为0的全部去掉
    for(int i = n1.size() - 1; i >= 0; --i) {
        if(n1[i] == 0) {
            n1.pop_back();
        }else {
            break;
        }
    }
    if(n1.empty()) {
        return "0";
    }

    for(int i = n2.size() - 1; i >= 0; --i) {
        if(n2[i] == 0) {
            n2.pop_back();
        }else {
            break;
        }
    }
    if(n2.empty()) {
        return "0";
    }

    std::vector<int> vecRes;
    for(int i = 0; i < n1.size(); ++i) {
        std::vector<int> tmp(i, 0);
        int sum = 0, carry = 0;
        for(int j = 0; j < n2.size(); ++j) {
            sum = (n1[i] * n2[j] + carry);
            carry = sum / 10;
            tmp.push_back(sum % 10);
        }

        if(carry) {
            tmp.push_back(carry);
        }

        addVec(vecRes, tmp);
    }

    std::string ans;
    for(int i = vecRes.size() - 1; i >= 0; --i) {
        ans.push_back(vecRes[i] + '0');
    }

    return ans;
}