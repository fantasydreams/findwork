#include "542.01Matrix.h"
#include <climits>

vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
{
    if(mat.size() == 0 || mat[0].size() == 0) {
        return {};
    }
    std::vector<std::vector<int>> dp(mat.size(), std::vector<int>(mat[0].size(), INT_MAX - 1));
    //从左上角到右下角进行一次动态规划，再从右下角到左上角进行一次动态规划
    for(int i = 0; i < mat.size(); ++i)
    {
        for(int j = 0; j < mat[i].size(); ++j)
        {
            if(mat[i][j] != 0) 
            {
                if(j > 0){
                    dp[i][j] = std::min(dp[i][j-1] + 1, dp[i][j]);
                }

                if(i > 0){
                    dp[i][j] = std::min(dp[i-1][j] + 1, dp[i][j]);
                }
            }else {
                dp[i][j] = 0;
            }
        }
    }

    //反向dp的时候注意起止位置，写代码的时候注意要一次行写完条件 pair之类的然后再写其他的逻辑，避免丢失犯错
    for(int i = mat.size() - 1; i >= 0; --i)
    {
        for(int j = mat[i].size() - 1; j >= 0; --j)
        {
            if(mat[i][j] != 0)
            {
                if(j < mat[i].size() - 1) {
                    dp[i][j] = std::min(dp[i][j], dp[i][j + 1] + 1);
                }

                if(i < mat.size() - 1) {
                    dp[i][j] = std::min(dp[i][j], dp[i + 1][j] + 1);
                }
            }
        }
    }

    return dp;
}