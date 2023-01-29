#include "310.MinimumHeightTrees.h"
#include <set>
#include <map>
#include <queue>

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
{
    std::vector<int> ans;
    if(n <= 2) 
    {
        for(int i = 0; i < n; ++i) {
            ans.push_back(i);
        }
        return ans;
    }

    std::map<int, std::set<int>> adj;
    for(const auto & edge : edges)
    {
        adj[edge[0]].insert(edge[1]);
        adj[edge[1]].insert(edge[0]);
    }

    std::set<int> leaves;
    for(const auto & node : adj)
    {
        if(node.second.size() == 1) {
            leaves.insert(node.first);
        }
    }

    int remainnode = n;
    while(remainnode > 2)
    {
        std::set<int> newleaves;
        for(auto & leaf : leaves)
        {
            for(const auto & node : adj[leaf])
            {
                // adj[leaf].erase(node); // 迭代的时候不要做删除操作
                adj[node].erase(leaf);
                if(adj[node].size() == 1) {
                    newleaves.insert(node);
                }
            }
            adj.erase(leaf);
        }
        remainnode -= leaves.size();
        swap(leaves, newleaves);
    }

    return std::vector<int>(leaves.begin(), leaves.end());
}


vector<int> findMinHeightTrees1(int n, vector<vector<int>>& edges)
{
    if(n == 0) {
        return {};
    }
    if(n == 1) {
        return {0};
    }

    std::vector<int> ans;
    std::vector<int> degree(n, 0);
    std::vector<std::vector<int>> adj(n);
    for(const auto & edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
        ++degree[edge[0]];
        ++degree[edge[1]];
    }

    std::queue<int> node;
    for(int i = 0; i < n; ++i)
    {
        if(degree[i] == 1) {
            node.push(i);
        }
    }

    while(node.size())
    {
        ans.clear();
        int size = node.size();
        for(int i = 0; i < size; ++i)
        {
            int u = node.front();
            node.pop();
            ans.push_back(u);
            for(auto & v : adj[u])
            {
                --degree[u];
                --degree[v];
                if(degree[v] == 1) {
                    node.push(v);
                }
            }
        }
    }

    return ans;
}