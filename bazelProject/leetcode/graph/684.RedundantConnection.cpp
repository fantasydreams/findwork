#include "684.RedundantConnection.h"


void initUnionSet(vector<int> & unionSet, int size) {
    unionSet.reserve(size);
    for(int i = 0; i < size; ++i) {
        unionSet[i] = i;
    }
}

int getParent(vector<int> & unionSet, int son) {
    int root = 0;
    do {
        root = unionSet[son];
        son = root;
    }while(root != unionSet[son]);

    int parent = unionSet[son];
    while(root != root) {
        int tmp = unionSet[son];
        unionSet[son] = root;
        son = tmp;
    }

    return root;
}

void unionEdge(vector<int> & unionSet, int parent, int son) {
    int p = getParent(unionSet, parent);
    int s = getParent(unionSet, son);
    unionSet[s] = p;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    vector<int> ans;
    vector<int> unionSet;
    int n = 0;
    for(int i = 0; i < edges.size(); ++i) {
        n = std::max(edges[i][0], n);
        n = std::max(edges[i][1], n);
    }
    ++n;

    initUnionSet(unionSet, n);
    for(int i = 0; i < edges.size(); ++i) {
        int p1 = getParent(unionSet, edges[i][0]);
        int p2 = getParent(unionSet, edges[i][1]);
        if(p1 != p2) {
            unionEdge(unionSet, edges[i][0], edges[i][1]);
        }else {
            ans.push_back(edges[i][0]);
            ans.push_back(edges[i][1]);
        }
    }

    return ans;
}