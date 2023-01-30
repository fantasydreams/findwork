#include "91.DecodeWays.h"
#include <unordered_set>
#include <vector>

bool checkdecode(const std::string & str, int pos, int len)
{
    if(len == 1)  {
        return str[pos] >= '1' && str[pos] <= '9';
    }else if(len == 2) {
        if(str[pos] == '0' || str[pos] > '2') {
            return false;
        }
        if(str[pos] == '2') {
            return str[pos + 1] >= '0' && str[pos + 1] <= '6';
        }
    }else {
        return false;
    }
    return true;
}

int numDecodings(string s)
{
    if(s.size() <= 0 || s[0] == '0') {
        return 0;
    }
    if(s.size() == 1) {
        return 1;
    }

    std::vector<int> dp(s.size() + 1, 1);
    for(int i = 1; i < s.size(); ++i)
    {
        bool cur = checkdecode(s, i, 1);
        bool pre = checkdecode(s, i - 1, 2); 
        if(!cur && !pre) {
            return 0;
        }
        
        if(cur && pre) {
            dp[i + 1] = dp[i] + dp[i - 1];
        }else if(cur) {
            dp[i + 1] = dp[i];
        }else {
            dp[i + 1] = dp[i - 1];
        }
    }

    return dp[s.size()];
}