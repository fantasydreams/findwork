#include "133.CloneGraph.h"
#include <unordered_map>
#include <queue>

Node* cloneGraph(Node* node) {
    if(node == nullptr) {
        return node;
    }

    std::unordered_map<Node*, Node*> map;
    std::queue<Node *> que; que.push(node);
    Node* ans = new Node(node->val);
    map[node] = ans;
    while(!que.empty()) {
        Node* node = que.front(); que.pop();
        for(auto pIter : node->neighbors) {
            if(map.count(pIter) == 0) {
                map[pIter] = new Node(pIter->val);
                que.push(pIter);
            }
            
            map[node]->neighbors.push_back(map[pIter]);
        }
    }

    return ans;
}


Node* cloneGraph1(Node* node) {
    if(node == nullptr) {
        return node;
    }

    std::unordered_map<Node*, Node*> hashmap;
    Node* pAns = new Node(node->val);
    hashmap[node] = pAns;
    std::queue<Node*> que; que.push(node);
    while(!que.empty()) {
        Node* pNode = que.front(); que.pop();
        for(auto pNeighbor : pNode->neighbors) {
            if(hashmap.count(pNeighbor) == 0) {
                hashmap[pNeighbor] = new Node(pNeighbor->val);
                que.push(pNeighbor);
            }

            hashmap[pNode]->neighbors.push_back(hashmap[pNeighbor]);
        }
    }

    return pAns;
}