#include "455.AssignCookies.h"
#include <algorithm>

int findContentChildren(std::vector<int>& g, std::vector<int>& s)
{
    if(g.size() == 0 || s.size() == 0) {
        return 0;
    }

    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());

    uint32_t iRes = 0;
    for(int iChild = 0,  iCookie = 0; iChild < g.size() && iCookie < s.size();)
    {
        if(g[iChild] <= s[iCookie])
        {
            ++iRes;
            ++iChild;
        }
        ++iCookie;
    }

    return iRes;
}