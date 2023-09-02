#include "65.ValidNumber.h"
#include <string>
#include <algorithm>

bool isValidNumber(const std::string& sStr, bool isInt) {
    std::string sNumber = sStr;
    if(!sStr.empty() && (sStr[0] == '+' || sStr[0] == '-')) {
        sNumber = sStr.substr(1);
    }

    if(sNumber.empty()) {
        return false;
    }

    // return sNumber.find_first_not_of(isInt ? "0123456789" : ".0123456789") == std::string::npos &&
    //         (isInt || (std::count(sNumber.begin(), sNumber.end(), '.') < 2 && sNumber != "."));

    if(isInt && sNumber.find_first_not_of("0123456789") != std::string::npos) {
        return false;
    }

    if(!isInt && (sNumber.find_first_not_of(".0123456789") != std::string::npos || std::count(sNumber.begin(), sNumber.end(), '.') >= 2 || sNumber == ".")) {
        return false;
    }

    return true;

}

bool isNumber(string s) {
    if(s.empty()) {
        return false;
    }
    auto iPos = s.find_first_of("eE");
    std::string sBase = s.substr(0, iPos);
    bool bBase = isValidNumber(sBase, true) || isValidNumber(sBase, false);
    bool bExpoent = iPos == std::string::npos || isValidNumber(s.substr(iPos + 1), true);
    return bBase && bExpoent;
}