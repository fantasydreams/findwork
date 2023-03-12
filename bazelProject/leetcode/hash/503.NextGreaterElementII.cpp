#include "503.NextGreaterElementII.h"
#include <climits>
#include <stack>
#include <algorithm>

vector<int> nextGreaterElements(vector<int>& nums) {
    if(nums.empty()) {
        return {};
    }


    int _max = nums[0];
    vector<int> acsend(1, _max);
    for(const auto & num : nums) {
        _max = std::max(_max, num);
        if(num > acsend.back()) {
            acsend.push_back(num);
        }
    }

    vector<int> ans(nums.size(), -1);
    stack<int> st;
    for(int idx = nums.size() - 1; idx >= 0; --idx) {
        while(!st.empty() && st.top() <= nums[idx]) {
            st.pop();
        }

        int larger = 0;
        if(nums[idx] != _max) {
            if(st.empty()) {
                larger = *std::upper_bound(acsend.begin(), acsend.end(), nums[idx]);
            }else {
                larger = st.top();
            }
            ans[idx] = larger;
        }
        st.push(nums[idx]);
    }

    return ans;
}