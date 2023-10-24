#include "147.InsertionSortList.h"
#include "linkcomm.h"
#include <map>

struct ValNode {
    ListNode* head;
    ListNode* tail;
    ValNode() : head(nullptr), tail(nullptr){};
    ValNode(ListNode* node) : head(node), tail(node) {
        head->next = nullptr;
    }

    ValNode(const ValNode& oValNode) {
        head = oValNode.head;
        tail = oValNode.tail;
    }
};

ListNode* insertionSortList(ListNode* head) {
    if(head == nullptr) {
        return head;
    }

    ListNode* pNode = head;
    std::map<int, struct ValNode> hashmap;
    while(pNode) {
        ListNode* pCurNode = pNode;
        pNode = pNode->next;
        auto pIter = hashmap.find(pCurNode->val);
        if(pIter == hashmap.end()) {
            hashmap.insert({pCurNode->val, ValNode(pCurNode)});
        }else {
            pIter->second.tail->next = pCurNode;
            pIter->second.tail = pCurNode;
            pIter->second.tail->next = nullptr;
        }
    }    

    ListNode* pre = nullptr;
    for(auto pIter = hashmap.begin(); pIter != hashmap.end(); ++pIter) {
        if(pre) {
            pre->next = pIter->second.head;
        }
        pre = pIter->second.tail;
    }

    return hashmap.begin()->second.head;
}


ListNode* insertionSortList1(ListNode* head) {
    if(head == nullptr) {
        return head;
    }

    ListNode* pNode = head;
    std::vector<struct ValNode> hashmap(10005);
    while(pNode) {
        ListNode* pCurNode = pNode;
        pNode = pNode->next;
        
        auto & item = hashmap[pCurNode->val + 5000];
        if(item.head == nullptr) {
            item.head = item.tail = pCurNode;
        }else {
            item.tail->next = pCurNode;
            item.tail = pCurNode;
        }
        pCurNode->next = nullptr;
    }    

    ListNode* newhead = nullptr;
    ListNode* pre = newhead;
    for(const auto& item : hashmap) {
        if(item.head) {
            if(newhead == nullptr) {
                newhead = item.head;
            }

            if(pre) {
                pre->next = item.head;
            }
            pre = item.tail;
        }
    }

    return newhead;
}