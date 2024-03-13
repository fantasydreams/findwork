#include "66.PlusOne.h"
#include <algorithm>

std::vector<int> plusOne(std::vector<int>& digits) {
    if(digits.empty()) {
        return std::vector<int>(1,1);
    }

    std::vector<int> ans = digits;

    std::reverse(ans.begin(), ans.end());
    int carry = 1, sum = 0;
    for(int i = 0;i < ans.size(); ++i) {
        sum = carry + ans[i];
        ans[i] = sum % 10;
        carry = sum / 10;
    }

    if(carry) {
        ans.push_back(carry);
    }

    for(int k = ans.size() - 1; k >= 0 && ans[k] == 0; --k) {
        ans.pop_back();
    }

    std::reverse(ans.begin(), ans.end());
    return ans;
}

std::vector<int> plusOne1(std::vector<int>& digits) {
    if(digits.empty()) {
        return {1};
    }

    int idx = 0;
    for(; idx < digits.size(); ++idx) {
        if(digits[idx]) {
            break;
        }
    }
    digits.erase(digits.begin(), digits.begin() + idx);

    int carry = 1;
    for(int i = digits.size() - 1; i >= 0; --i) {
        int sum = digits[i] + carry;
        carry = sum / 10;
        digits[i] = sum % 10;
    }

    if(carry) {
        digits.insert(digits.begin(), carry);
    }

    return digits;
}
