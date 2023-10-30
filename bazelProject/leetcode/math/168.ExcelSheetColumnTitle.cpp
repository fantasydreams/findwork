#include "168.ExcelSheetColumnTitle.h"
#include <algorithm>
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


string convertToTitle1(int columnNumber) {
    std::vector<int> hash;
    hash.push_back('Z');
    for(int i = 0; i < 25; ++i) {
        hash.push_back('A' + i);
    }

    std::string ans;
    while(columnNumber) {
        int mod = columnNumber % 26;
        if(mod == 0) {
            ans.push_back('Z');
            columnNumber -= 26;
        }else {
            ans.push_back(hash[mod]);
        }
        columnNumber /= 26;
    }
    

    reverse(ans.begin(), ans.end());
    return ans;
}


string convertToTitle2(int columnNumber) {  
    std::string ans;
    while(columnNumber) {
        ans.push_back('A' + (columnNumber-1) % 26);
        columnNumber = (columnNumber - 1) / 26;
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}