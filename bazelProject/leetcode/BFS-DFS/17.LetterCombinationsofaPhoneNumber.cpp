#include "17.LetterCombinationsofaPhoneNumber.h"
#include <map>

void GetCombination(const std::string& sDigits, int pos, std::vector<std::string>& ans, std::string sTmp) {
    static map<int, std::string> digitsMap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };

    if(pos >= sDigits.size()) {
        if(!sTmp.empty()) {
            ans.emplace_back(sTmp);
        }
        return;
    }
    
    for(const auto& ch : digitsMap[sDigits[pos]]) {
        GetCombination(sDigits, pos + 1, ans, sTmp + ch);
    }

    return;
}

void eraseInvalid(std::string& sInput)
{
    std::string ans;
    for(const auto& ch : sInput) {
        if(ch >= '2' && ch <= '9') {
            ans += ch;
        }
    }
    sInput = ans;
}
vector<string> letterCombinations(string digits)
{
    vector<std::string> ans;
    std::string sTmp;
    eraseInvalid(digits);
    GetCombination(digits, 0, ans, sTmp);
    return ans;
}

void GetCombination1(const std::string& sDigits, int pos, std::vector<std::string>& ans, std::string& sTmp) {
    static map<int, std::string> digitsMap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };

    if(pos >= sDigits.size()) {
        if(!sTmp.empty()) {
            ans.push_back(sTmp);
        }
        return;
    }

    for(const auto& ch : digitsMap[sDigits[pos]]) {
        sTmp.push_back(ch);
        GetCombination1(sDigits, pos + 1, ans, sTmp);
        sTmp.pop_back();
    }
}

vector<string> letterCombinations1(string digits) {
    std::vector<std::string> ans;
    std::string sTmp;
    eraseInvalid(digits);
    GetCombination1(digits, 0, ans, sTmp);
    return ans;
}