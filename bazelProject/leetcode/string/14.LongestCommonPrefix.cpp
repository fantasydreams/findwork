
#include "14.LongestCommonPrefix.h"

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string res = "";
    if (strs.size() == 0) {
        return res;
    }

    if(strs.size() == 1){
        return strs[0];
    }

    bool isContinue = true;
    for (size_t k = 0; k < strs[0].size() && isContinue; ++k)
    {
        for (size_t i = 1; i < strs.size(); ++i)
        {
            if (strs[i].size() <= k || strs[i - 1][k] != strs[i][k])
            {
                isContinue = false;
                break;
            }
            if (i == strs.size() - 1)
            {
                res += strs[strs.size() - 1][k];
            }
        }
    }
    return res;
}

string longestCommonPrefix_1(vector<string> &strs)
{
    if(strs.size() == 0) return "";
    string res = strs[0];
    for(size_t i = 0;i < strs.size() && res.size();++i)
    {
        if(strs[i].size() == 0) return "";
        for(int j = 0; j < strs[i].size() && j < res.size(); ++j)
        {
            if(strs[i][j] != res[j])
            {
                res = res.substr(0,j);
                break;
            }
            if(j == strs[i].size() -1){
                res = strs[i];
            }
        }
    }
    return res;
}