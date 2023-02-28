#include "168.ExcelSheetColumnTitle.h"
#include <string>
#include <numeric>
#include <vector>
#include <cmath>

string convertToTitle(int columnNumber) {
    std::vector<int> hash;
    hash.push_back('Z');
    for(int i = 0; i < 25; ++i) {
        hash.push_back('A' + i);
    }

    std::string ans;
    while(columnNumber) {
        int mod = (columnNumber % 26);
        if(mod == 0) {
            ans += 'Z';
            columnNumber -= 26;
        }else {
            ans += hash[mod];
        }
        columnNumber /= 26;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}