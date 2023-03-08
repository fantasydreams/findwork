#include "739.DailyTemperatures.h"
#include <stack>

vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> ans(temperatures.size(), 0);
    stack<std::pair<int, int>> st;
    for(int i = 0; i < temperatures.size(); ++i) {
        while(!st.empty() && temperatures[i] > st.top().first) {
            auto [tmp, idx] = st.top();
            st.pop();
            ans[idx] = i - idx;
        }

        st.push({temperatures[i], i});
    }

    return ans;
}

vector<int> dailyTemperatures1(vector<int>& temperatures) {
    vector<int> ans(temperatures.size(), 0);
    stack<int> st;
    for(int i = 0; i < temperatures.size(); ++i) {
        while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int idx = st.top();
            st.pop();
            ans[idx] = i - idx;
        }

        st.push(i);
    }

    return ans;
}