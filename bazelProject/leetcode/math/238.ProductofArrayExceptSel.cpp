#include "238.ProductofArrayExceptSel.h"
#include <map>
#include <iostream>

vector<int> productExceptSelf(vector<int>& nums) {
    int64_t product = 1;
    vector<int> ans;
    int zeroCnt = 0;
    ans.resize(nums.size());
    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i]) {
            if(zeroCnt <= 1) {
                product *= nums[i];
            }
        }else {
            ++zeroCnt;
        }
    }

    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] != 0){
            if(zeroCnt) {
                ans[i] = 0;
            }else {
                ans[i] = product / nums[i];
            }
        }else {
            if(zeroCnt > 1) {
                ans[i] = 0;
            }else {
                ans[i] = product;
            }
        }
    }

    return ans;
}


vector<int> productExceptSelf1(vector<int>& nums) {
    vector<int> ans(nums.size(), 1);
    int Product = nums.empty() ? 1 : nums[0];
    for(int i = 1; i < nums.size(); ++i) {
        ans[i] = Product;
        Product *= nums[i];
    }
    
    Product = nums.empty() ? 1 : nums[nums.size() - 1];
    for(int i = nums.size() - 2; i >= 0; --i) {
        ans[i] *= Product;
        Product *= nums[i];
    }

    return ans;
}


vector<int> productExceptSelf2(vector<int>& nums) {
    vector<int> ans(nums.size(), 0);    
    int product = 1;
    for(int i = 0; i < nums.size(); ++i) {
        ans[i] = product;
        // std::cout << ans[i] << " " << product << std::endl;
        product *= nums[i];
    }

    product = 1;
    for(int i = nums.size() - 1; i >= 0; --i) {
        ans[i] *= product;
        product *= nums[i];
    }

    return ans;
}
