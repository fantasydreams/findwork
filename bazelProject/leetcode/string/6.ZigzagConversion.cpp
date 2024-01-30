#include "6.ZigzagConversion.h"
#include <vector>

//硬模拟
std::string convert(std::string s, int numRows)
{
    if(numRows <= 1) return s;
    std::vector<std::string> matrix(numRows);
    int line = 0;
    int direction = 1;
    for(size_t idx = 0; idx < s.size(); ++idx)
    {   
        matrix[line] += s[idx];
        if(line + direction * 1 < 0 || line + direction * 1 >= numRows){
            direction *= -1;
        }

        line += direction * 1;
    }

    std::string res;
    for(const auto & str : matrix){
        res += str;
    }

    return res;
}


std::string convert1(std::string s, int numRows) {
    std::string sAns;
    if(numRows <= 1) {
        return s;
    }

    std::vector<std::string> matrix(numRows);
    int iLine = 0, iDirection = 1;
    for(int i = 0; i < s.size(); ++i) {
        matrix[iLine] += s[i];
        if(iLine + iDirection * 1 < 0 || iLine + iDirection * 1 >= numRows) {
            iDirection *= -1;
        }

        iLine += iDirection * 1;
    }

    for(const auto & str : matrix) {
        sAns += str;
    }

    return sAns;
}