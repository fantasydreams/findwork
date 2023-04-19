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