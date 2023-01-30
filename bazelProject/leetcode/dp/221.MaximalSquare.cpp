#include "221.MaximalSquare.h"
#include <vector>

// 一种常见的做法是定义一个二维 dp 数组，其中 dp[i][j] 表示满足题目条件的、以 (i, j) 为右下角的正方形或者长方形的属性。对于本题，
// 则表示 以 (i, j) 为右下角的全由 1 构成的最大正方形面积。如果当前位置是 0，那么 dp[i][j] 即为 0;如果 当前位置是 1，我们假设 dp[i][j] = k2，
// 其充分条件为 dp[i-1][j-1]、dp[i][j-1] 和 dp[i-1][j] 的值必须 都不小于 (k − 1)2，否则 (i, j) 位置不可以构成一个边长为 k 的正方形。
// 同理，如果这三个值中的 的最小值为 k − 1，则 (i, j) 位置一定且最大可以构成一个边长为 k 的正方形。
int maximalSquare(vector<vector<char>>& matrix)
{
    if(matrix.size() == 0 || matrix[0].size() == 0) {
        return 0;
    }

    int m = matrix.size(), n = matrix[0].size();
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
    // dp[i][j] = x 表示从i, j结尾 变长为 x 是正方形
    int ans = 0;
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(matrix[i][j] == '1')
            {
                if(i == 0 || j == 0) {
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = std::min(std::min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]) + 1;
                }
                ans = std::max(ans, dp[i][j]);
            }
        }
    }

    return ans * ans;
}