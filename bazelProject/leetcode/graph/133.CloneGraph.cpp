#include "133.CloneGraph.h"

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