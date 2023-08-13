#include "42.TrappingRainWater.h"

int trap(vector<int>& height) {
    if(height.empty() || height.size() == 1) {
        return 0;
    }

    int LeftMaxH = 0, rightMaxH = 0;
    int water = 0;
    int left = 0, right = height.size() - 1;
    while(left < right) {
        if(height[left] <= height[right]) {
            if(height[left] > LeftMaxH) {
                LeftMaxH = height[left];
            }else {
                water += (LeftMaxH - height[left]);
                ++left;
            }
        }else {
            if(height[right] > rightMaxH) {
                rightMaxH = height[right];
            }else {
                water += (rightMaxH - height[right]);
                --right;
            }
        }
    }

    return water;
}