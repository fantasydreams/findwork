#include "394.DecodeString.h"

std::string decodeStringRe(std::string subStr)
{
    if(subStr.size() == 0) return "";
    std::string res;

    int product = 0;
    int peidx = 0, pbidx = 0;
    while(pbidx < subStr.size() && !(subStr[pbidx] >='0' && subStr[pbidx] <= '9')){
        ++pbidx;
    }
    while(peidx < subStr.size() && subStr[peidx] != '['){
        ++peidx;
    }

    product = std::stol(subStr.substr(pbidx, peidx - pbidx + 1));

    int bracket = 0;
    for(int i = peidx; i < subStr.size(); ++i){
        if(subStr[i] == '[') {
            ++bracket;
        } 
    }

    std::string pstr;
    if(bracket == 1) {
        pstr = subStr.substr(peidx + 1, subStr.size() - peidx - 2);
    }else {
        pstr = decodeString(subStr.substr(peidx + 1, subStr.size() - peidx - 2));
    }

    while(product--){
        res += pstr;
    }

    if(pbidx){
        res = subStr.substr(0, pbidx) + res;
    }
    return res;
}


std::string decodeString(std::string s)
{
    std::string res;
    for(int i = s.size() - 1; i >= 0; --i)
    {
        if(s[i] != ']'){
            res.insert(res.begin(), s[i]);
        }else
        {
            int endBracket = 1;
            int start = i - 1;
            while(start >= 0)
            {
                if(endBracket == 0)
                {
                    if(!(s[start]>= '0' && s[start] <= '9')){
                        break;
                    }
                }
                else if(s[start] == ']') {
                    ++endBracket;
                }else if(s[start] == '['){
                    --endBracket;
                }
                --start;
            }
            // printf("%d %s\n", start, s.substr(start + 1, i - start).c_str());
            res.insert(0, decodeStringRe(s.substr(start + 1, i - start)));
            i = start + 1;
        }
    }
    return res;
}