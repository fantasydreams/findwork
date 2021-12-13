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