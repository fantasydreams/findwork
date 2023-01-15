#include "75.SortColors.h"

void sortColors(vector<int>& nums)
{
    int red = 0, blue = nums.size() - 1, tmp = 0;
    while(tmp <= blue)
    {
        if(nums[tmp] == 1) {
            ++tmp;
        }else if(nums[tmp] == 2) 
        {
            swap(nums[tmp], nums[blue]);
            --blue;
        }else 
        {
            swap(nums[red], nums[tmp]);
            ++red;
            ++tmp;
        }
    }
}