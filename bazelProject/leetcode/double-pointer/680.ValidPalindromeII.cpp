#include "680.ValidPalindromeII.h"

bool validPalindrome(string s)
{
    size_t b = 0, e = s.size()-1;
    while(b < e)
    {
        if(s[b] != s[e]) 
        {
            if(s[b + 1] == s[e]) 
            {
                bool isP = true;
                size_t tb = b + 1, te = e;
                while(tb < te)
                {
                    if(s[tb++] != s[te--]) 
                    {
                        isP = false;
                        break;
                    }
                }
                
                if (isP) {
                    return true;
                }
            }
            
            if(s[b] == s[e-1]) 
            {
                size_t tb = b, te = e - 1;
                while(tb < te)
                {
                    if(s[tb++] != s[te--]) {
                        return false;
                    }
                }
                return true;
            }

            return false;
        }
        ++b;
        --e;
    }

    return true;
}