#include "67.AddBinary.h"
#include <algorithm>

string addBinary(string a, string b) {
    const auto & sShort = a.size() < b.size() ? a : b;
    auto & sLong = a.size() < b.size() ? b : a;
    int base = 2;
    
    int iShort = sShort.size() - 1, iLong = sLong.size() - 1, carry = 0, sum;
    while(iShort >= 0 && iLong >= 0) {
        sum = -2 * '0' + sShort[iShort--] + sLong[iLong] + carry;
        sLong[iLong--] = sum % base + '0';
        carry = sum / base;
    }

    while(carry) {
        if(iLong >= 0) {
            sum = - '0' + sLong[iLong] + carry;
            sLong[iLong--] = sum % base + '0';
            carry = sum / base;
        }else {
            sLong.insert(sLong.begin(), carry + '0');
            break;
        }
    }

    return sLong;
}


string addBinary1(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if(a.length() > b.length()) {
        swap(a, b);
    }

    int carry = 0, idx = 0;
    while(idx < a.size()) {
        int sum = a[idx] + b[idx] - 2 * '0' + carry;
        carry = sum / 2;
        b[idx++] = sum % 2 + '0';
    }

    while(idx < b.size() && carry) {
        int sum = b[idx] - '0' + carry;
        carry = sum / 2;
        b[idx++] = sum % 2 + '0';
    }

    if(carry) {
        b.push_back(carry + '0');
    }

    reverse(b.begin(), b.end());
    return b;
}