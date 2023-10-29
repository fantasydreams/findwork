#include "171.ExcelSheetColumnNumber.h" 

int titleToNumber(string columnTitle) {
    int ans = 0;
    uint64_t base = 1;
    for(int i = columnTitle.size() - 1; i >= 0; --i) {
        ans += (columnTitle[i] - 'A' + 1) * base;
        base *= 26;
    }

    return ans;
}


int titleToNumber1(string columnTitle) {
    int ans = 0;
    for(int i = 0; i < columnTitle.size(); ++i) {
        ans = ans * 26 + (columnTitle[i] - 'A' + 1); // 注意这里的括号的作用
    }

    return ans;
}