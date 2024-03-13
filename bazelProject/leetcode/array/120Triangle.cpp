#include "120Triangle.h"
#include <algorithm>


void dfs(const vector<vector<int> >& triangle, int row, int col, int& _min, int curSum) {
    if(triangle.size() <= row || triangle[row].size() <= col) {
        return;
    }
    
    if(triangle.size() == row + 1) {
        if(_min > curSum + triangle[row][col]) {
            _min = curSum + triangle[row][col];
        }
        return;
    }
    
    // 当前元素的下面的元素
    dfs(triangle, row + 1, col, _min, curSum + triangle[row][col]);
    // 当前元素的下面元素的后面一个元素
    dfs(triangle, row + 1, col + 1, _min, curSum + triangle[row][col]);
}

int minimumTotal(vector<vector<int> >& triangle) {
    int _min = INT_MAX, curSum = 0;
    dfs(triangle, 0, 0, _min, curSum);
    return _min;
}


int minimumTotalDp(vector<vector<int> >& triangle) {
    std::vector<std::vector<int> >dp(triangle.size(), std::vector<int>(triangle.size(), 0));
    dp[0][0] = triangle[0][0];
    for(int i = 1; i < triangle.size(); ++i) {
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        for(int k = 1; k <= i; ++k) {
            if(k == i) {
                dp[i][k] = dp[i - 1][k - 1] + triangle[i][k];
            }else {
                dp[i][k] = std::min(dp[i - 1][k - 1], dp[i - 1][k]) + triangle[i][k];
            }
        }
    }

    return *std::min_element(dp[triangle.size() - 1].begin(), dp[triangle.size() - 1].end());
}

void dfs1(const vector<vector<int> >& triangle, int row, int col, int& _min, int curSum) {
    if(triangle.size() <= row || triangle[row].size() <= col) {
        return;
    }

    if(triangle.size() == row + 1) {
        _min = std::min(_min, curSum + triangle[row][col]);
        return;
    }

    dfs1(triangle, row + 1, col, _min, curSum + triangle[row][col]);
    dfs1(triangle, row + 1, col + 1, _min, curSum + triangle[row][col]);
}

int minimumTotal1(vector<vector<int> >& triangle) {
    int _min = INT_MAX, curSum = 0;
    dfs1(triangle, 0, 0, _min, curSum);
    return _min;
}


int minimumTotalDp1(vector<vector<int> >& triangle) {
    if(triangle.empty()) {
        return 0;
    }

    std::vector<std::vector<int> > dp;
    dp.push_back({triangle[0][0]});
    for(int i = 1; i < triangle.size(); ++i) {
        std::vector<int> dp1(triangle[i].size(), INT_MAX);
        dp1[0] = dp[i - 1][0] + triangle[i][0];
        for(int k = 1; k < triangle[i].size(); ++k) {
            if(k == triangle[i].size() - 1) {
                dp1[k] = dp[i - 1][k - 1] + triangle[i][k];
            }else {
                dp1[k] = std::min(dp[i - 1][k - 1], dp[i - 1][k]) + triangle[i][k];
            }
        }
        dp.emplace_back(dp1);
    }

    return *min_element(dp.back().begin(), dp.back().end());
}