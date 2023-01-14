#include "76.MinimumWindowSubstring.h"
using namespace std;
string minWindow(string s, string t)
{
    int arrWindow[128] = {0};
    for(auto ch : t){
        ++arrWindow[ch];
    }

    int l = 0, start = 0, minLen = INT_MAX;
    int cnt  = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if((arrWindow[s[i]]--) > 0) {
            ++cnt;
        }
        while(cnt == t.size())
        {
            if(i - l + 1 < minLen) 
            {
                start = l;
                minLen = i - l + 1;
            }
            if(++arrWindow[s[l++]] > 0) {
                --cnt;
            }
        }
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}