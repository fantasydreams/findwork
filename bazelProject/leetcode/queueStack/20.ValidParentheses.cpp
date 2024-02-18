#include "20.ValidParentheses.h"
#include <stack>
#include <map>

//'(', ')', '{', '}', '[' and ']'

bool isValid(string s) {
    static map<char, char> chMap = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    stack<char> st;
    for(const auto & ch : s) {
        auto pIter = chMap.find(ch);
        if(pIter == chMap.end()) {
            st.push(ch);
        }else {
            if(st.empty() || st.top() != pIter->second) {
                return false;
            }
            st.pop();
        }
    }

    return st.empty();
}


bool isValid1(string s)
{
    static map<char, char> chMap = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    stack<char> st;
    for(const auto& ch : s) {
        auto pIter = chMap.find(ch);
        if(pIter == chMap.end()) {
            st.push(ch);
        }else {
            if(st.empty() || pIter->second != st.top()) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}


bool isValid2(string s) {
    if(s.empty()) {
        return true;
    }

    std::stack<char> st;
    for(const auto & ch : s) {
        if(ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }else {
            if(st.empty()) {
                return false;
            }

            char pop = st.top();
            st.pop();
            if((ch == ')' && pop == '(') || (ch == ']' && pop == '[') || (ch == '}' && pop == '{')) {
                continue;
            }
            return false;
        }
    }

    return st.empty();
}