#include "605.CanPlaceFlowers.h"

bool canPlaceFlowers(std::vector<int>& flowerbed, int n)
{
    for(int i=0; i < flowerbed.size() && n; ++i)
    {
        if(flowerbed[i] == 0)
        {
            bool bLeftPlate = (i > 0) ? flowerbed[i - 1] : false;
            bool bRightPlate = (i < flowerbed.size() - 1) ? flowerbed[i + 1] : false;
            if(!bLeftPlate && !bRightPlate)
            {
                --n;
                flowerbed[i] = 1;
            }
        }
    }

    return n == 0;
}