#include <queue>

// Definition for a Node.




Node* connect(Node* root) {
    std::queue<Node* > que;
    if(root) {
        que.push(root);
    }

    while(!que.empty()) {
        int size = que.size() - 1;
        Node* pPre = que.front(); que.pop();
        if(pPre->left) {
            que.push(pPre->left);
        }
        if(pPre->right) {
            que.push(pPre->right);
        }

        while(size--) {
            Node* pCur = que.front(); que.pop();
            pPre->next = pCur;
            pPre = pCur;
            
            if (pCur->left){
                que.push(pCur->left);
            }
            if (pCur->right){
                que.push(pCur->right);
            }
        }
    }

    return root;   
}
