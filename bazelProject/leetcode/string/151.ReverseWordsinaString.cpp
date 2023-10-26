#include "151.ReverseWordsinaString.h"
#include <algorithm>
#include <string>

string reverseWords(string s) {
    std::string sAns;
    if(s.empty()) {
        return sAns;
    }

    std::vector<std::string> vec;
    std::string tmp;
    for(int i = 0; i <= s.size(); ++i) {
        if(s[i] == ' ' || i == s.size()) {
            if(!tmp.empty()) {
                vec.emplace_back(std::move(tmp));
                tmp.clear();
            }

            continue;
        }

        tmp += s[i];
    }

    for(int i = vec.size() - 1; i >= 0; --i) {
        if(!sAns.empty()) {
            sAns += " ";
        }
        sAns += vec[i];
    }

    return sAns;
}



string reverseWords1(string s) {
    std::string sAns;
    if(s.empty()) {
        return sAns;
    }

    std::string tmp;
    for(int i = 0; i <= s.size(); ++i) {
        if(s[i] == ' ' || i == s.size()) {
            if(!tmp.empty()) {
                std::reverse(tmp.begin(), tmp.end());
                sAns += " ";
                sAns += tmp;
                tmp.clear();
            }
            continue;
        }

        tmp += s[i];
    }

    std::reverse(sAns.begin(), sAns.end());
    if(!sAns.empty()) {
        sAns.pop_back();
    }
        
    return sAns;
}