#include "239.SlidingWindowMaximum.h"
#include <set>
#include <queue>

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    multiset<int, std::greater<int>> mSet;
    for(decltype(nums.size()) idx = 0; idx < k - 1; ++idx) {
        mSet.insert(nums[idx]);
    }

    vector<int> ans;
    for(decltype(nums.size()) idx = k - 1; idx < nums.size(); ++idx) {
        mSet.insert(nums[idx]);
        ans.push_back(*mSet.begin());
        mSet.erase(mSet.find(nums[idx - (k - 1)]));
    }

    return ans;
}


vector<int> maxSlidingWindow_1(vector<int>& nums, int k) {
        std::vector<int> ans;
        std::multiset<int, std::greater<int> > set;
        for(int i = 0; i < k - 1  && i < nums.size(); ++i) {
            set.insert(nums[i]);
        }

        for(int i = k - 1; i < nums.size(); ++i) {
            set.insert(nums[i]);
            ans.push_back(*set.begin());
            set.erase(set.find(nums[i - k + 1]));
        }

        return ans;
    }


vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
    deque<int> dq;
    for(int i = 0; i < k - 1; ++i) {
        while(!dq.empty() && nums[i] > dq.back()) {
            dq.pop_back();
        }
        dq.push_back(nums[i]);
    }

    vector<int> ans;
    for(decltype(nums.size()) i = k - 1; i < nums.size(); ++i) {
        while(!dq.empty() && nums[i] > dq.back()) {
            dq.pop_back();
        }
        dq.push_back(nums[i]);
        ans.push_back(dq.front());
        if(nums[i - k + 1] == dq.front()) {
            dq.pop_front();
        }
    }

    return ans;
}


vector<int> maxSlidingWindow1_1(vector<int>& nums, int k) {
        std::vector<int> ans;
        std::deque<int> dq;
        for(int i = 0; i < k - 1 && i < nums.size(); ++i) {
            while(!dq.empty() && nums[i] > dq.back()) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }

        for(int i = k - 1; i < nums.size(); ++i) {
            while(!dq.empty() && nums[i] > dq.back()) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            ans.push_back(dq.front());
            if(nums[i - k + 1] == dq.front()) { // 这种并不保险，还是存下标是比较稳妥的方式
                dq.pop_front();
            }
        }

        return ans;
    }

vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;
    for(decltype(nums.size()) i = 0; i < nums.size(); ++i) {
        if(!dq.empty() && (dq.front() == i - k)) {
            dq.pop_front();
        }

        while(!dq.empty() && nums[i] > nums[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);

        if(i >= k - 1) {
            ans.push_back(nums[dq.front()]);
        }
    }

    return ans;
}

vector<int> maxSlidingWindow2_1(vector<int>& nums, int k) {
        std::vector<int> ans;
        std::deque<int> dq;
        for(int i = 0 ; i < nums.size(); ++i) {
            if(i >= k  && !dq.empty() && dq.front() == (i - k)) {
                dq.pop_front();
            }

            while(!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);

            if(i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
