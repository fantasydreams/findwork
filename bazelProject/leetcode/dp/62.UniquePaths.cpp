#include "62.UniquePaths.h"

int uniquePaths(int m, int n) {
    std::vector<std::vector<int> >dp(m, std::vector<int>(n, 0));

    for(int r = 0; r < m; ++r) {
        for(int c = 0; c < n; ++c) {
            if(r == 0 || c == 0) {
                dp[r][c] = 1;
            }else {
                dp[r][c] = dp[r - 1][c] + dp[r][c - 1];
            }
        }
    }

    return dp[m - 1][n - 1];
}

void DFS(int m, int n, int r, int c, int& ans) {
    if(r == m - 1 && c == n - 1) {
        ++ans;
    }
    if(r >= m || c >= n) {
        return;
    }

    DFS(m, n, r, c + 1, ans);
    DFS(m, n, r + 1, c, ans);
}


int uniquePathsDFS(int m, int n) {
    int ans = 0;
    DFS(m, n, 0, 0, ans);
    return ans;
}