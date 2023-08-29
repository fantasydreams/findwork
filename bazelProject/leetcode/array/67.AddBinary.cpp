#include "67.AddBinary.h"
#include <algorithm>

string addBinary(string a, string b) {
    if(a.empty() && b.empty()) {
        return "0";
    }

    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    int i = 0, carry = 0, sum;
    std::string ans;
    while(i < a.size() && i < b.size()) {
        sum = carry + a[i] + b[i] - 2 * '0';
        ans += '0' + sum % 2;
        carry = sum / 2;
        ++i;
    }

    while(i < a.size()) {
        sum = carry + a[i] - '0';
        ans += '0' + sum % 2;
        carry = sum / 2;
        ++i;
    }

    while(i < b.size()) {
        sum = carry + b[i] - '0';
        ans += '0' + sum % 2;
        carry = sum / 2;
        ++i;
    }
    
    if(carry) {
        ans.push_back('1');
    }

    for(int i = ans.size() - 1; i > 0 && ans[i] == '0'; --i) {
        ans.pop_back();
    }

    std::reverse(ans.begin(), ans.end());

    return ans;
}