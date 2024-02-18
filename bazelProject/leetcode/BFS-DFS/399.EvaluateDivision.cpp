#include "399.EvaluateDivision.h"
#include "unordered_map"
#include <unordered_map>
#include <queue>
#include <string>

vector<double> calcEquation(vector<vector<string> >& equations, vector<double>& values, vector<vector<string> >& queries) {
    std::vector<double> vecAns;
    std::unordered_map<string, std::unordered_map<string, double> > neighbors;
    for(int i = 0; i < equations.size(); ++i) {
        neighbors[equations[i][0]].insert({equations[i][1], values[i]});
        neighbors[equations[i][1]].insert({equations[i][0], 1.0 / values[i]});
    }     
    
    for(auto q : queries) {
        std::unordered_map<std::string, double> tmp;
        const auto& a = q[0];
        const auto& b = q[1];
        if(neighbors.find(a) == neighbors.end() || neighbors.find(b) == neighbors.end()) {
            vecAns.push_back(-1);
            continue;
        }
        std::queue<std::string> que;
        que.push(a);
        tmp[a] = 1;
        while(!que.empty()) {
            std::string sCur = que.front(); que.pop();
            if(sCur == b) {
                break;
            }

            for(const auto & nei : neighbors[sCur]) {
                if(tmp.count(nei.first)) {
                    continue;
                }

                tmp[nei.first] = nei.second * tmp[sCur];
                if(nei.first == b) {
                    break;
                }
                que.push(nei.first);
            }
        }
        
        if(tmp.count(b)) {
            vecAns.push_back(tmp[b]);
        }else {
            vecAns.push_back(-1);
        }
    }

    return vecAns;
}