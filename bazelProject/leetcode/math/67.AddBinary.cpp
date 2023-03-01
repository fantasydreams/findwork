#include "67.AddBinary.h"

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