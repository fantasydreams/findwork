#include "433.MinimumGeneticMutation.h"
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

int minMutation(string startGene, string endGene, vector<string>& bank) {
    if(startGene.length() != endGene.length()) {
        return -1;
    }

    int iAns = 0;
    static vector<char> vecCh = {'A', 'C', 'G', 'T'};
    unordered_set<std::string> setBank(bank.begin(), bank.end());
    unordered_set<std::string> setMid;
    std::queue<std::string> que; que.push(startGene);
    while(!que.empty()) {
        ++iAns;
        int iSize = que.size();
        while(iSize--) {
            std::string sStr = que.front(); que.pop();
            for(int i = 0; i < sStr.size(); ++i) {
                for(const auto& ch : vecCh) {
                    if(ch == sStr[i]) {
                        continue;
                    }

                    std::string sTmp = sStr;
                    sTmp[i] = ch;
                    if(setMid.count(sTmp) || setBank.count(sTmp) == 0) {
                        continue;
                    }

                    if(sTmp == endGene) {
                        return iAns;
                    }
                    
                    que.push(sTmp);
                    setMid.insert(sTmp);
                }
            }
        }
        
    }

    return -1;
}