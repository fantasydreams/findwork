#include "504.Base7.h"

string convertToBase7(int num) {
    if(num == 0) {
        return "0";
    }

    std::string ans;
    bool neg = false;
    if(num < 0) {
        num = -num;
        neg = true;
    }

    while(num) {
        ans += (num % 7) + '0';
        num /= 7;
    }

    if(neg == true) {
        ans += '-';
    }

    reverse(ans.begin(), ans.end());
    return ans;
}