#include "52.N-QueensII.h"
#include <vector>
#include <cmath>



bool checkValid(const std::vector<int>& col, int new_col) {
    for(int i = 0; i < col.size(); ++i) {
        if(abs(i - (int)col.size()) == abs(new_col - col[i]) || new_col == col[i]) {
            return false;
        }
    }
    return true;
}

void dfs(int n, std::vector<int>& col, int & cnt) {
    if(n == col.size()) {
        ++cnt;
        return;
    }

    for(int i = 0; i < n; ++i) {
        if(!checkValid(col, i)) {
            continue;
        }
        col.push_back(i);
        dfs(n, col, cnt);
        col.pop_back();
    }
}


int totalNQueens(int n) {
    int ans = 0;
    if(n == 0) {
        return ans;
    }

    std::vector<int> col;
    dfs(n, col, ans);
    return ans;
}

bool isValid(const std::vector<int>& col, int new_col) {
    for(int i = 0; i < col.size(); ++i) {
        if(abs(i - (int)col.size()) == abs(new_col - col[i]) || new_col == col[i]) {
            return false;
        }
    }
    return true;
}

void traceback(int n, std::vector<int>& col, int& iAns) {
    if(col.size() == n) {
        ++iAns;
        return;
    }

    for(int i = 0; i < n; ++i) {
        if(isValid(col, i)) {
            col.push_back(i);
            traceback(n, col, iAns);
            col.pop_back();
        }
    }
}

int totalNQueens1(int n) {
    int iAns = 0;
    if(n == 0) {
        return iAns;
    }

    std::vector<int> col;
    traceback(n, col, iAns);
    return iAns;
}