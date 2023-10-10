#include "131.PalindromePartitioning.h"

bool isPalindrome(const std::string & str)
{
    int s = 0, e = str.size() - 1;
    while(s < e)
    {
        if(str[s] != str[e]){
            return false;
        }
        ++s;
        --e;
    }
    return true;
}

void Getpartition(const std::string & s, int start, std::vector<std::vector<std::string> > & res, std::vector<std::string> & vec)
{
    if(start >= s.size())
    {
        res.emplace_back(vec);
        return ;
    }

    for(int len = 1; len <= s.size() - start; ++len)
    {
        if(isPalindrome(s.substr(start, len))) 
        {
            vec.push_back(s.substr(start, len));
            Getpartition(s,start + len , res, vec);
            vec.pop_back();
        }
    }
}


//时间复杂度O(N * 2^N)，最糟糕的情况是substring一共有2^N个
std::vector<std::vector<std::string> > partition(std::string s)
{
    std::vector<std::vector<std::string> >res;
    std::vector<std::string> tmp;
    Getpartition(s, 0, res, tmp);
    return res;
}



//使用dp还能掠过去单独去判断整个字符串是否是回文串
void GetpartitionDp(const std::string & s, int start,
     std::vector<std::vector<std::string> > & res, 
     std::vector<std::string> & vec,
     std::vector<std::vector<bool> > & dp)
{
    if(start >= s.size())
    {
        res.push_back(vec);
        return;
    }

    for(int end = start; end < s.size(); ++end)
    {
        if((s[start] == s[end]) && ((end - start <= 2) || ((start + 1 < s.size() && end - 1 >= 0) && dp[start + 1][end - 1] == true))) 
        {
            vec.push_back(s.substr(start, end - start + 1));
            dp[start][end] = true;
            GetpartitionDp(s,end + 1 , res, vec, dp);
            vec.pop_back();
        }
    }
}


std::vector<std::vector<std::string> > partitionDp(std::string s)
{
    std::vector<std::vector<std::string> >res;
    std::vector<std::string> tmp;
    std::vector<std::vector<bool> > dp(s.size(), std::vector<bool>(s.size(), 0));
    GetpartitionDp(s, 0, res, tmp, dp);
    return res;
}


void GetpartitionDp1(const std::string & s, int start,
     std::vector<std::vector<std::string> > & res, 
     std::vector<std::string> & vec,
     std::vector<std::vector<bool> > & dp) 
{
    if(s.empty()) {
        return;
    }

    if(start >= s.size()) {
        res.push_back(vec);
        return;
    }

    for(int end = start; end < s.size(); ++end) {
        if((s[start] == s[end] && ((end - start <= 2) || (start + 1 < s.size() && end - 1 >= 0 && dp[start + 1][end - 1])))) {
            std::string substr = s.substr(start, end - start + 1);
            dp[start][end] = true;
            vec.emplace_back(std::move(substr));
            GetpartitionDp1(s, end + 1, res, vec, dp) ;
            vec.pop_back();
        }
    }

}

std::vector<std::vector<std::string> > partitionDp1(std::string s) {
    std::vector<std::vector<std::string> >res;
    std::vector<std::string> tmp;
    std::vector<std::vector<bool> > dp(s.size(), std::vector<bool>(s.size(), 0));
    GetpartitionDp1(s, 0, res, tmp, dp);
    return res;
}