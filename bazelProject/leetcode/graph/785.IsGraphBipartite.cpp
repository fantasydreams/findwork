#include "785.IsGraphBipartite.h"
#include <queue>

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    if(n == 0) {
        return true;
    }

    std::queue<int> que;
    std::vector<int> color(n, 0);
    for(int i =0; i < n; ++i) {
        if(!color[i]) {
            color[i] = 1;
            que.push(i);
        }

        while(!que.empty()) {
            int node = que.front(); que.pop();
            for(const auto & adj : graph[node]) {
                if(color[adj] == 0) {
                    que.push(adj);
                    color[adj] = color[node] == 1 ? 2 : 1;
                }else if(color[adj] == color[node]){
                    return false;
                }
            }
        }
    }

    return true;
}