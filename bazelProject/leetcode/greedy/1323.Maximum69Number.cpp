#include "1323.Maximum69Number.h"
#include <cmath>
#include <climits>
#include <cstdio>

int maximum69Number (int num)
{
    int ninePos = -1, sixPos = -1;
    int tmpNum = num, bit;
    for(int i = 0; tmpNum; ++i)
    {
        bit = abs(tmpNum % 10);
        tmpNum /= 10;
        if(bit == 6 && i > sixPos) {
            sixPos = i;
        }
        if(bit == 9 && i > ninePos) {
            ninePos = i;
        }
    }

    if(num >= 0) 
    {
        if(sixPos >= 0){
            return num + 3 * pow(10, sixPos);
        }else {
            return num;
        }
    }else 
    {
        if(ninePos >= 0) {
            return num + 3 * pow(10, ninePos);
        }else {
            return num;
        }
    }
    return 0;
}
