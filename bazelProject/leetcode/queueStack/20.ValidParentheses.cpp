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