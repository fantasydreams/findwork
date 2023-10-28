#include "166.FractiontoRecurringDecimal.h"
#include <cstdlib>
#include <ostream>
#include <string>
#include <map>
#include <iostream>

string fractionToDecimal(int numerator, int denominator) {
    if((int64_t)numerator % denominator == 0) {
        return std::to_string((int64_t)numerator / denominator);
    }    

    std::string ans = numerator < 0 ^ denominator < 0 ? "-" : "";
    uint64_t num = abs((int64_t)numerator); // 这种情况一定要考虑边界条件
    uint64_t denum = abs((int64_t)denominator);
    ans += std::to_string(num / denum) + ".";
    
    map<std::pair<uint64_t, uint64_t>, int> hash_map;
    num = num % denum;
    while(num) {
        num *= 10;
        int up = num / denum;
        num %= denum;
        // std::cout << "up " <<  up << " num " << num <<std::endl;
        if(num == 0) {
            ans += std::to_string(up);
            return ans;
        }else {
            auto pIter = hash_map.find({up, num});
            if(pIter != hash_map.end()) {
                ans.insert(ans.begin() + pIter->second, '(');
                ans.push_back(')');
                return ans;
            }
        }
        ans += std::to_string(up);

        hash_map.insert({{up, num}, (int)ans.size() - 1});
    }
    return ans;
}