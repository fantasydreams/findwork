#include "11.ContainerWithMostWater.h"
#include <algorithm>

int maxArea(std::vector<int>& height)
{
    if(height.size() <= 1){
        return 0;
    } 
    int start = 0, end = height.size() - 1;
    int maxHeight = 0;
    while(start < end)
    {
        int tmpProduct = std::min(height[start], height[end]) *  (end - start);
        if(tmpProduct > maxHeight) {
            maxHeight = tmpProduct;
        }

        if(height[start] < height[end]){
            ++start;
        }else if(height[start] > height[end]){
            --end;
        }else{ // 这里不管谁遇到start 和 end都会比当前的积小，所以两个都可以移动
            ++start;
            --end;
        }
    }
    return maxHeight;
}