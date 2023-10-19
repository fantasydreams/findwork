#include "140.WordBreakII.h"
#include <unordered_map>
#include <unordered_set>
#include <iostream>


void dfs(std::vector<bool>& dp, const std::string& str, std::vector<string> &ans, int pre, std::vector<string>& path, const std::unordered_set<std::string>& hash) {
    if(pre >= str.size()) {
        if(path.empty()) {
            return;
        }

        std::string str = path[0];
        for(int i = 1; i < path.size(); ++i) {
            str += " ";
            str += path[i];
        }

        ans.push_back(std::move(str));
        return;
    }
    
    for(int loc = pre + 1; loc <= str.size(); ++loc) {
        if(dp[loc] == false) {
            continue;
        }
        
        std::string tmp = str.substr(pre, loc - pre);
        if(!hash.count(str.substr(pre, loc - pre))) {
            // std::cout << tmp << std::endl;
            continue;
        }

        path.push_back(std::move(tmp));
        dfs(dp, str, ans, loc, path, hash);
        path.pop_back();
    }
}


vector<string> wordBreak(string s, vector<string>& wordDict) {
    std::vector<string> ans;
    if(s.empty()) {
        return ans;
    }

    std::vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for(int i = 1; i <= s.size(); ++i) {
        for(const auto & word : wordDict) {
            if(word.size() > i) {
                continue;
            }
            if(!dp[i] && (s.substr(i - word.size(), word.size()) == word)) {
                dp[i] = dp[i - word.size()];
            }
        }
    }

    // for(int i = 0; i < dp.size(); ++i) {
    //     if(i == 0) {
    //         std::cout << dp[i];
    //     }else {
    //         std::cout << " " << dp[i];
    //     }
    // }
    // std::cout << std::endl;
    

    if(dp[s.size()] == false) {
        return ans;
    }

    std::vector<std::string> path;
    std::unordered_set<std::string> hash(wordDict.begin(), wordDict.end());
    dfs(dp, s, ans, 0, path, hash);
    return ans;
}