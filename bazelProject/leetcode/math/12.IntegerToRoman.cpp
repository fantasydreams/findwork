
#include "12.IntegerToRoman.h"
#include <fstream>
#include <functional>
#include <string>
#include <map>
#include <cmath>

/*
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/
std::string intToRoman(int num)
{
    std::string sRes;
    static std::map<uint32_t, std::string> mapIntergerToRoman = {
        {1, "I"},
        {4, "IV"},
        {5, "V"},
        {9, "IX"},
        {10, "X"},
        {40, "XL"},
        {50, "L"},
        {90, "XC"},
        {100, "C"},
        {400, "CD"},
        {500, "D"},
        {900, "CM"},
        {1000, "M"}
    };

    int iLen = 0, iTemp = num;
    while(iTemp)
    {
        iTemp /= 10;
        ++iLen;
    }

    while(iLen > 0)
    {
        int iBase = pow(10, iLen - 1);
        int iCurNum = (num / iBase) % 10;
        auto pIter = mapIntergerToRoman.find(iCurNum * iBase);
        if(pIter != mapIntergerToRoman.end()) {
            sRes += pIter->second;
        }else 
        {
            if(iCurNum != 5)
            {
                if(iCurNum > 5)
                {
                    auto pFiveBase = mapIntergerToRoman.find(5 * iBase);
                    if(pFiveBase == mapIntergerToRoman.end()) {
                        continue;
                    }
                    sRes += pFiveBase->second;
                    iCurNum -= 5;
                } 

                auto pBase = mapIntergerToRoman.find(iBase);
                if(pBase == mapIntergerToRoman.end()){
                    continue;
                }

                for(int i = 0; i < iCurNum; ++i){
                    sRes += pBase->second;
                }
            }else
            {
                auto pIter = mapIntergerToRoman.find(5 * iBase);
                if(pIter != mapIntergerToRoman.end()) {
                    sRes += pIter->second;
                }
            }
        }

        --iLen;
    }

    return sRes;
}


std::string intToRoman1(int num) {
    std::string sRes;
    static std::map<uint32_t, std::string, std::greater<int> > mapIntergerToRoman = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"},
    };

    for(const auto& oPair : mapIntergerToRoman) {
        while(num >= oPair.first) {
            sRes += oPair.second;
            num -= oPair.first;
        }

        if(num == 0) {
            break;
        }
    }

    return sRes;
}