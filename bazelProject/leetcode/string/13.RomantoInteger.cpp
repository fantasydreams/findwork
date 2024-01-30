#include "13.RomantoInteger.h"
#include <map>

int romanToInt(std::string s)
{
    std::map<char, int> rmap = 
    {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000},
    };

    int res = 0;
    for(size_t i = 0; i < s.size(); ++i)
    {
        int neg = 1;
        if(i + 1 < s.size())
        {
            if(rmap[s[i]] < rmap[s[i + 1]]){
                neg = -1;
            }
        }
        res += neg * rmap[s[i]];
    }

    return res;
}


int romanToInt2(std::string s)
{
    std::map<char, int> rmap = {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000},
    };

    int pre = INT_MIN;
    int res = 0;
    for(int i = s.size() - 1; i >= 0; --i) {
        int neg = 1;
        if(pre > rmap[s[i]]){
            neg = -1;
        }
        res += neg * rmap[s[i]];
        pre = rmap[s[i]];
    }

    return res;
}



int char2int(char c)
{
    switch(c){
        case 'I':return 1;
        case 'V':return 5;
        case 'X':return 10;
        case 'L':return 50;
        case 'C':return 100;
        case 'D':return 500;
        case 'M':return 1000;
        default:return 0;
    }
}


int romanToInt1(std::string s) 
{
    int pre = INT_MAX;
    int num = 0;
    for(int i=0;i<s.size();++i)
    {
        int cur = char2int(s[i]);
        if(pre < cur) num = num + cur - 2 * pre;
        else num += cur;
        pre = cur;
    }
    
    return num;
}
    
    
    
int romanToInt3(std::string s)
{
    std::map<char, int> rmap = {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000},
    };

    int pre = INT_MIN;
    int res = 0;
    for(int i = s.size() - 1; i >= 0; --i) {
        int neg = 1;
        if(pre > rmap[s[i]]){
            neg = -1;
        }
        res += neg * rmap[s[i]];
        pre = rmap[s[i]];
    }

    return res;
}
 


int romanToIntForward(std::string s)  {
    int pre = INT_MAX, num = 0;
    for(int i=0;i<s.size();++i) {
        int cur = char2int(s[i]);
        if(pre < cur) {
            num += cur;
            num -= 2 * pre; 
        }else {
            num += cur;
        }
        
        pre = cur;
    }
    
    return num;
}