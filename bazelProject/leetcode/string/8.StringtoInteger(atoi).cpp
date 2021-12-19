#include "8.StringtoInteger(atoi).h"


//这个是支持++--12 = 12，--12 = 12， -12 = -12
int myAtoi1(std::string s) 
{
    int posres = 0;
    int positive = 1;
    int idx = 0;
    while(idx < s.size() && s[idx] == ' '){
        ++idx;
    }

    // -- = +
    while(idx < s.size() && (s[idx] == '-' || s[idx] == '+'))
    {
        if(s[idx] == '-'){
            positive = positive * -1;
        }   
        ++idx;
    }

    while(idx < s.size() && (s[idx] >= '0' && s[idx] <= '9'))
    {
        int num = s[idx] - '0';
        if(posres * positive < INT_MIN / 10 || (posres * positive == INT_MIN / 10 && num >= 8)){
            return INT_MIN;
        }
        if(posres * positive > INT_MAX || (posres * positive == INT_MAX/10 && num >= 8)){
            return INT_MAX;
        }

        posres = posres * 10 + num;
        ++idx;
    }
    
    return posres * positive;
}


int myAtoi(std::string s) 
{
    int posres = 0;
    int positive = 1;
    int idx = 0;
    while(idx < s.size() && s[idx] == ' '){
        ++idx;
    }

    // -- = +
    /*
    while(idx < s.size() && (s[idx] == '-' || s[idx] == '+'))
    {
        if(s[idx] == '-'){
            positive = positive * -1;
        }   
        ++idx;
    }
    */
    if(s[idx] == '-' || s[idx] == '+')
    {
        if(s[idx] == '-'){
            positive = -1;
        }
        ++idx;
    }

    while(idx < s.size() && (s[idx] >= '0' && s[idx] <= '9'))
    {
        int num = s[idx] - '0';
        if(posres * positive < INT_MIN / 10 || (posres * positive == INT_MIN / 10 && num >= 8)){
            return INT_MIN;
        }
        if(posres * positive > INT_MAX / 10 || (posres * positive == INT_MAX / 10 && num >= 8)){
            return INT_MAX;
        }

        posres = posres * 10 + num;
        ++idx;
    }
    
    return posres * positive;
}