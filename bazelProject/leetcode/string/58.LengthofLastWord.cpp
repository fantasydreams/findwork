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