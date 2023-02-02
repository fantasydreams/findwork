#include "72.EditDistance.h"
#include <vector>

// dp[i][j] 表示字符串1 0-i 位置 与字符串2 0-j位置所需要编辑的最少次数
// dp[0][*] = * //如果一个字符串的长度为0，那么到另一个字符串的最少编辑长度为删除另一个字符串或者插入与非空字符串一样的，编辑长度为非空字符串的长度
// dp[*][0] = *
// 对于word1[i-1] = word[j-1]，那么最短编辑长度dp[i][j]就为 min(dp[i][j], dp[i-1][j-1]);
// 对于word1[i-1] = word[j-1]，分两种情况，修改/删除插入
// 修改：dp[i-1][j-1] + 1; 在字符串1 i位置删除 或者 字符串2j位置插入 dp[i-1][j] + 1; 在字符串2 i位置插入 或者字符串2j位置删除 dp[i][j-1]

int minDistance(string word1, string word2)
{
    int _max = std::max(word1.size(), word2.size()) + 1;
    std::vector<std::vector<int>> dp(word1.size() + 1, std::vector<int>(word2.size() + 1, _max));
    for(int i = 0; i <= word1.size(); ++i)
    {
        for(int j = 0; j <= word2.size(); ++j)
        {
            if(i == 0) {
                dp[i][j] = j; //要删除或者创建这么多
            }else if(j == 0) {
                dp[i][j] = i; //要删除或者创建这么多
            }else 
            {
                if(word1[i - 1] == word2[j - 1]) { //相等看前面的就行了
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1]);
                }else { //不相等有两种情况，一种删除一种修改
                    dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }
    }    

    return dp[word1.size()][word2.size()];
}