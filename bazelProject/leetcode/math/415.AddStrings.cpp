#include "415.AddStrings.h"

string addStrings(string num1, string num2) {
    auto & sLong = num1.size() > num2.size() ? num1 : num2;
    const auto & sShort = num1.size() > num2.size() ? num2 : num1;
    int iPoss = sShort.size() - 1, iPosL = sLong.size() - 1, sum, carry = 0;
    while(iPoss >= 0 && iPosL >= 0) {
        sum = sShort[iPoss--] + sLong[iPosL] + carry - 2 * '0';
        sLong[iPosL--] = sum % 10 + '0';
        carry = sum /= 10;
    }

    while(carry) {
        if(iPosL >= 0) {
            sum = sLong[iPosL] + carry - '0';
            carry = sum / 10;
            sLong[iPosL--] = sum % 10 + '0';
        }else {
            sLong.insert(sLong.begin(), carry + '0');
            break;
        }
    }

    return sLong;
}


string addStrings1(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    auto & sLong = num1.size() > num2.size() ? num1 : num2;
    auto & sShort = num1.size() > num2.size() ? num2 : num1;
    int pos = 0, sum = 0, carry = 0;
    while(pos < sShort.size() && pos < sLong.size()) {
        sum = sLong[pos] + sShort[pos] - 2 * '0' + carry;
        sLong[pos++] = sum % 10 + '0';
        carry = sum / 10;
    }

    while(carry) {
        if(pos < sLong.size()) {
            sum = sLong[pos] - '0' + carry;
            sLong[pos++] = sum % 10 + '0';
            carry = sum / 10;
        }else {
            sLong += ('0' + carry);
            break;
        }
    }

    reverse(sLong.begin(), sLong.end());
    return sLong;
}