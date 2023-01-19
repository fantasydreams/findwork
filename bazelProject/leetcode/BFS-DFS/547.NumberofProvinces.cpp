#include "547.NumberofProvinces.h"

void DFS(vector<vector<int>> & isConnected, vector<bool> & vecVisited, int i)
{   
    vecVisited[i] = true;
    for(int k = 0; k < isConnected[i].size(); ++k)
    {
        if(isConnected[i][k] && !vecVisited[k]) {
            DFS(isConnected, vecVisited, k);
        }
    }
}

int findCircleNum(vector<vector<int>> & isConnected)
{
    int cnt = 0;
    vector<bool> vecVisited(isConnected.size(), false);
    for(int i = 0; i < isConnected.size(); ++i)
    {
        if(isConnected[i][i] && !vecVisited[i])
        {
            ++cnt;
            DFS(isConnected, vecVisited, i);
        }
    }
    return cnt;
}

int getparent(vector<int> & parent, int i)
{
    int root = parent[i];
    while(root != parent[root]) {
        root = parent[root];
    }

    int son = i, tmp;
    while(parent[son] != root)
    {
        tmp = parent[son];
        parent[son] = root;
        son = tmp;
    }

    return root;
}

void uion(vector<int> & parent, int i, int j)
{
    int parent1 = getparent(parent, i);
    int parent2 = getparent(parent, j);
    parent[parent2] = parent[parent1];
}


//并查集
int findCircleNum1(vector<vector<int>> & isConnected)
{
    vector<int> parent(isConnected.size(), 0);
    for(int i = 0; i < isConnected.size(); ++i) {
        parent[i] = i;
    }

    for(int i = 0; i < isConnected.size(); ++i)
    {
        for(int j = 0; j < isConnected[i].size(); ++j)
        {
            if(isConnected[i][j]) {
                uion(parent, i, j);
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < isConnected.size(); ++i) 
    {
        if(parent[i] == i) {
            ++cnt;
        }
    }

    return cnt;
}