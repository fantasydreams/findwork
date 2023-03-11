#include "332.ReconstructItinerary.h"
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <set>

vector<string> findItinerary(vector<vector<string>>& tickets) {
    unordered_map<std::string, multiset<std::string>> hash_map;
    for(const auto & vec : tickets) {
        hash_map[vec[0]].insert(vec[1]);
    }
    
    vector<string> ans;
    stack<string> st;
    st.push("JFK");
    while(!st.empty()) {
        auto & sCur = st.top();
        if(hash_map[sCur].empty()) {
            ans.push_back(sCur);
            st.pop();
        }else {
            st.push(*hash_map[sCur].begin());
            hash_map[sCur].erase(hash_map[sCur].begin());
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}