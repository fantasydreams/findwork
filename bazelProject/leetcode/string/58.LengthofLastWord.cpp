#include "58.LengthofLastWord.h"

int lengthOfLastWord(std::string s) {
    int ans = 0;
    for(int i = s.size() - 1; i >= 0; --i) {
        if(s[i] == ' ' && ans) {
            return ans;
        }else if(s[i] != ' '){
            ++ans;
        }
    }

    return ans;
}


int lengthOfLastWordStdString(std::string s) {
    auto iPos = s.find_last_not_of(" ");
    if(iPos == std::string::npos) {
        return s.size();
    }

    auto iBackSpace = s.find_last_of(' ', iPos);
    if(iBackSpace == std::string::npos) {
        return iPos + 1;
    }

    return iPos - iBackSpace;
}