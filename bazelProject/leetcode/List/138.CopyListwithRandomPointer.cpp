#include "138.CopyListwithRandomPointer.h"
#include <unordered_map>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


Node* copyRandomList(Node* head) {
    if(!head) {
        return head;
    }

    std::unordered_map<Node*, Node*> hashMap;
    Node *tmp = head;
    while(tmp) {
        hashMap[tmp] = new Node(tmp -> val);
        tmp = tmp->next;
    } 

    tmp = head;
    while(tmp) {
        if(tmp->next) {
            hashMap[tmp]->next = hashMap[tmp->next];
        }
        hashMap[tmp]->random = hashMap[tmp->random];
        tmp = tmp -> next;
    }

    return hashMap[head];
}

Node* copyRandomList1(Node* head) {
    if(!head) {
        return head;
    }

    // merge copy
    Node* tmp = head;
    while(tmp) {
        Node* node = new Node(tmp->val);
        node->next = tmp->next;
        tmp->next = node;
        tmp = tmp -> next -> next;
    }

    // copy rand ptr
    tmp = head;
    while(tmp) {
        if(tmp->random) {
            tmp -> next -> random = tmp->random->next;
        }
        tmp = tmp->next -> next;
    }

    //split
    tmp = head;
    Node* newHead = tmp->next;
    while(tmp) {
        Node* newNode = tmp->next;
        tmp->next = newNode->next;
        tmp = tmp->next;
        if(newNode->next) {
            newNode->next = tmp->next;
        }
    }

    return newHead;
}


Node* copyRandomListHash(Node* head) {
    if(head == nullptr) {
        return nullptr;
    }

    Node * newHead = new Node(head->val);
    std::unordered_map<Node*, Node*> hashMap(head, newHead);
    Node* pTmp = head->next, *pPre = newHead;
    while(pTmp) {
        Node* pNode = new Node(pTmp->val);
        hashMap[pTmp] = pNode;
        pPre->next = pNode;
        pPre = pNode;
        pTmp = pTmp->next;
    }

    pTmp = head;
    while(pTmp) {
        hashMap[pTmp]->random = hashMap[pTmp->random];
        pTmp = pTmp->next;
    }

    return newHead;
}

// merge copy  copy random split
Node* copyRandomListON(Node* head) {
    if(head == nullptr) {
        return head;
    }

    Node* pTmp = head;
    while(pTmp) {
        Node* pNode = new Node(pTmp->val);
        pNode->next = pTmp->next;
        pTmp->next = pNode;
        pTmp = pNode->next;
    }

    // copy random
    pTmp = head;
    while(pTmp) {
        if(pTmp->random) {
            pTmp->next->random = pTmp->random->next;
        }
        pTmp = pTmp->next->next;
    }

    // split;
    
    pTmp = head;
    Node* newHead = pTmp->next;
    while(pTmp) {
        Node* pNode = pTmp->next;
        pTmp->next = pNode->next;
        pTmp = pTmp->next;
        if(pTmp) {
            pNode->next = pTmp->next;
        }
    }

    return newHead;
}

Node* copyRandomListON1(Node* head) {
    if(head == nullptr) {
        return head;
    }

    // copy
    Node *pNode = head;
    while(pNode) {
        Node* pTmp = new Node(pNode->val);
        pTmp->next = pNode->next;
        pNode->next = pTmp;

        pNode = pTmp->next;
    }

    // assgin ramdon
    pNode = head;
    while(pNode) {
        if(pNode->random) {
            pNode->next->random = pNode->random->next;
        }
        pNode = pNode->next->next;
    }

    // split;
    pNode = head;
    Node newHead(0);
    Node* pPre = &newHead;
    while(pNode) {
        pPre->next = pNode->next;
        pPre = pPre->next;
        pNode->next = pPre->next;
        pNode = pNode->next;
    }

    return newHead.next;
}

