#include "93.RestoreIPAddresses.h"
#include <string>
#include <set>

bool checkValid(const std::string& str) {
    if(str.empty()) {
        return false;
    }

    if(str[0] == '0' && str.size() > 1) {
        return false;
    }

    int value = std::stoul(str);
    if(value >= 0 && value <= 255) {
        return true;
    }

    return false;
}

void dfs(const std::string& str, int pos, std::vector<std::string> tmp, vector<string>& ans) {
    if(pos >= str.size() || tmp.size() >= 4) {
        if(pos < str.size()) {
            return;
        }
        
        if(tmp.size() == 4) {
            std::string record = tmp[0];
            for(int i = 1; i < tmp.size(); ++i) {
                record += '.';
                record += tmp[i];
            }
            ans.emplace_back(record);
        }
        return;
    }

    // 每次进来都当成新的
    if(tmp.size() < 4) {
        std::string sNew;
        sNew += str[pos];
        tmp.emplace_back(sNew);
        dfs(str, ++pos, tmp, ans);
    }
    // 给当前的dot新增字符
    
    while(tmp.back().size() < 3 && pos < str.size()) {
        std::string sNew = tmp.back() + str[pos];
        if(checkValid(sNew)) {
            tmp.back() = sNew;
            dfs(str, ++pos, tmp, ans);
        }else {
            break;
        }
    }
}


vector<string> restoreIpAddresses(string s) {
    vector<string> ans, tmp;
    dfs(s, 0, tmp, ans);
    // std::set<std::string> unique(ans.begin(), ans.end());
    // vector<string> returnAns(unique.begin(), unique.end());
    return ans;
}