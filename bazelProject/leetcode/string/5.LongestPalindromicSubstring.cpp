#include "5.LongestPalindromicSubstring.h"
#include <vector>
#include <algorithm>
#include <inttypes.h>
//普通算法，以某个字符为中心，向两边扩展来计算最大回文字串
//时间复杂度：O(n^2)，空间复杂度O(n)
std::string longestPalindrome(std::string s)
{
    std::string tmpRes;
    if(s.size() == 0)return tmpRes;
    std::string tmpStr;
    for(size_t idx = 0; idx < s.size(); ++idx){
        tmpStr += "#";
        tmpStr += s[idx];
    }
    tmpStr += "#";

    for(size_t idx = 1; idx < tmpStr.size(); ++idx)
    {
        int64_t left = idx, right = idx;
        while(left >= 0 && right < tmpStr.size() && tmpStr[left] == tmpStr[right])
        {
            int64_t len = right - left + 1;
            if(len > tmpRes.size()){
                tmpRes = tmpStr.substr(left, len);
            }
            --left, ++right;
        }
    }

    std::string res;
    for(size_t idx = 0; idx < tmpRes.size(); ++idx){
        if(tmpRes[idx] != '#'){
            res += tmpRes[idx];
        }
    }

    return res;
}

//同样以某个字符或者某两个字符作为中心，但是不借助辅助字符来判断
//时间复杂度O(n^2)，空间复杂度O(1)
//but two slow...
std::string GetLongestPalindromeWithCenter(const std::string & s, int64_t iCLeft, int64_t iCRight)
{
    std::string res;
    while(iCLeft >= 0 && iCRight <s.size() && s[iCLeft] == s[iCRight])
    {
        if(iCRight - iCLeft + 1 > res.size()){
            res = s.substr(iCLeft, iCRight - iCLeft + 1);
        }
        ++iCRight;
        --iCLeft;
    }

    return res;
}

std::string longestPalindromeWithoutAsistant(std::string s)
{
    std::string res;
    for(size_t idx = 0; idx < s.size(); ++idx)
    {
        std::string tmp1 = GetLongestPalindromeWithCenter(s, idx, idx);
        std::string tmp2;
        if(idx + 1 < s.size()){
            tmp2 = GetLongestPalindromeWithCenter(s, idx, idx + 1);
        }
        std::string tmp = tmp1.size() > tmp2.size() ? tmp1 : tmp2;
        if(tmp.size() > res.size()){
            res = tmp;
        }
    }

    return res;
}

// 使用DP
// 初始条件 dp[i] = true, else false
// dp迭代条件 dp[i-1,j+1] = dp[i,j] && s[i - 1] == s[j + 1], dp[i][j] = true if j-i == 1 && s[i] == s[j]
// 空间复杂度O(n^2), 时间复杂度o(n^2)
std::string longestPalindromeWithDP(std::string s)
{
    if(s.size() == 0) return s;
    std::vector<std::vector<bool> > dp(s.size(), std::vector<bool>(s.size(), false));
    for(int i = 0; i < s.size(); ++i)
    {
        dp[i][i] = true;
        if(i + 1 < s.size()){
            dp[i][i + 1] = (s[i] == s[i + 1]); // 偶数的情况
        }
    }
    int start = 0, len = 0;
    
    /* 错误更新dp的方式，这里依赖了还没更新的数据，不能保证最终的结果是正确的
    for(int i = 0; i < s.size() ; ++i)
    {
        for(int j = i; j < s.size(); ++j)
        {
            //这里一定要先更新dp[i][j]，因为dp[i-1][j+1]以来dp[i][j]
            if(i == j){
                dp[i][j] = true;
            }else if(j == i + 1){
                dp[i][j] = s[i] == s[j];
            }else{
                dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
            }

            if(dp[i][j])
            {
                int _len = j - i + 1;
                if(_len > len)
                {
                    start = i;
                    len = _len;
                }
            }
        }
    }
    */
    
    
    // 正确dp，永远记住现在是更新dp[i][j]，这里更新能保证依赖到的数据都是已经更新了准确的
    for(int j = 0; j < s.size(); ++j)
    {
        for(int i = j; i >= 0; --i)
        {
            if(i == j) {
                dp[i][j] = true;
            }
            else if(j == i + 1) {
                dp[i][j] = s[i] == s[j];
            }
            else{
                dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
            }

            if(dp[i][j]) 
            {
                if(j - i + 1 > len)
                {
                    start = i;
                    len = j - i + 1;
                }
            }
        }
    }

    return s.substr(start, len);
}


void printVec(std::vector<int> & vec)
{
    for(size_t idx = 0; idx < vec.size(); ++idx){
        printf("%d ", vec[idx]);
    }
    printf("\n");
} 
// Manacher's Algorithm
// 马拉车算法
/*
# 奇数情况
@#1#2#1$
11114111

对于第一种情况

--------------------|------max_r-------|
--------i--------max_idx-------idx-----|-----
---------------------------------------_last

i 是 idx关于max_idx对称的点， 由于idx的范围在[max_idx + 1, max_idx + max_r] 的范围内，
因此vecMa[idx] 的值与vecMa[i]的值有关，由于vecMa[i]的半径，是有可能超过max_idx的覆盖范围的，因此取
边界即min(vecMa[i], _last-idx), 由于（max_idx - max_r, max_idx + max_r）取开区间，因此这里是_last_idx

对于第二种情况
--------------------|------max_r-------|
-----------------max_idx---------------|-------idx--
---------------------------------------_last

显然idx关于max_idx的对称点不在这个覆盖范围内，因此这种情况就需要重新去扫描，从R = 1 开始扫描得到vecMa[idx]的值
这种情况就和以某个点为中心去搜索最长回文串一致

*/
std::string longestPalindromeManacher(std::string s)
{
    if(s.size() == 0){
        return s;
    }

    std::string sTmpStr = "@";
    for(size_t idx = 0; idx < s.size(); ++idx) 
    {
        sTmpStr += "#";
        sTmpStr += s[idx];
    }
    sTmpStr += "#$";

    size_t max_idx = 0, max_r = 0;
    std::vector<int> vecMa(sTmpStr.size(), 0);
    for(size_t idx = 1; idx < sTmpStr.size() - 1; ++idx)
    {
        int _last = max_idx + max_r;
        vecMa[idx] = _last > idx ? std::min(vecMa[2*max_idx - idx], (int)(_last - idx)) : 1;
        while(sTmpStr[idx - vecMa[idx]] == sTmpStr[idx + vecMa[idx]]) {
            ++vecMa[idx];
        }

        if(vecMa[idx] > max_r)
        {
            max_r = vecMa[idx];
            max_idx = idx;
        }
    }

    // printVec(vecMa);
    size_t origIdx = (max_idx - max_r)/2;
    return s.substr(origIdx, max_r - 1);
}

std::string getPalindromeAxis(const std::string & str, int s, int e)
{
    std::string ans;
    while(s >=0 && e < str.size() && str[s] == str[e]) {
        ans = str.substr(s, e - s + 1);
        --s;
        ++e;
    }

    return ans;
}

std::string longestPalindrome1(std::string s)
{
    std::string ans;
    for(int i = 0; i < s.size(); ++i) {
        std::string tmp = getPalindromeAxis(s, i, i);
        if(tmp.size() > ans.size()) {
            ans = tmp;
        }

        tmp = getPalindromeAxis(s, i, i + 1);
        if(tmp.size() > ans.size()) {
            ans = tmp;
        }
    }   

    return ans;

std::string longestPalindromeManacher1(std::string s)
{
    std::string tmp = "$";
    for(const auto & ch : s) {
        tmp += "#";
        tmp += ch;
        // printf("%s\n", tmp.c_str());
    }
    tmp += "#@";

    std::vector<int> vecMa(tmp.size(), 0);
    int curCenter = 0, curR = 0, maxCenter = 0, maxR = 0, last;
    for(int i = 1; i < tmp.size() - 1; ++i) {
        last = curCenter + curR;
        if(last > i) {
            vecMa[i] = std::min(last - i, vecMa[2 * curCenter - i]);
        }
        // printf("%c %c %d %d %d\n", s[i - vecMa[i] - 1], s[i + vecMa[i] + 1], i, i - vecMa[i] - 1, i + vecMa[i] + 1);
        while(tmp[i - vecMa[i] - 1] == tmp[i + vecMa[i] + 1]) {
            ++vecMa[i];
        }

        if(vecMa[i] > maxR) {
            maxCenter = i;
            maxR = vecMa[i];
        }

        if(i + vecMa[i] > last) {
            curCenter = i;
            curR = vecMa[i];
        }
    }
    // printVec(vecMa);
    return s.substr((maxCenter - maxR) / 2, maxR);
}