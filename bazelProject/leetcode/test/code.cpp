#include "code.h"
#include <string>


int echo(int num) {
    return num;
}


void getReplacedString(std::string& rawStr, const std::string& strMatch, const std::string& sReplace) {
    if(strMatch.size() < sReplace.size()) {
        return;
    }

    size_t iPos = 0;
    int rePlaceCnt = 0;
    iPos = rawStr.find(strMatch);
    while(iPos != std::string::npos) {
        ++rePlaceCnt;
        for(int idx = 0, idxRe = 0; idx < strMatch.size(); ++idx) {
            if(idxRe < sReplace.size()) {
                rawStr[iPos + idx] = sReplace[idxRe];
                ++idxRe;
            }else {
                rawStr[iPos + idx] = (char)0;
            }
        }
        iPos = rawStr.find(strMatch, iPos);
    }

    // int idxFast = 0, idxSlow = 0;
    // while(idxFast < rawStr.size()) {
    //     while(strMatch[idxFast] == (char)0 && idxFast < rawStr.size()) {
    //         ++idxFast;
    //     }
    //     while(idxSlow < idxFast && strMatch[idxSlow] != (char)0 && idxSlow < rawStr.size()) {
    //         ++idxSlow;
    //     }

    //     if(rawStr[idxSlow] != (char)0) {
    //         ++idxFast;
    //         continue;
    //     }

    //     if(idxSlow < rawStr.size() && idxFast < rawStr.size()) {
    //         std::swap(rawStr[idxFast], rawStr[idxSlow]);
    //     }
    //     ++idxSlow;
    //     ++idxFast;
    // }
    
    rawStr.resize(rawStr.size() - rePlaceCnt * (strMatch.size() - sReplace.size()));
}