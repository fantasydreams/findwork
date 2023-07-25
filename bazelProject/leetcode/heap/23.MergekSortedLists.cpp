#include "23.MergekSortedLists.h"
#include <queue>

class compare{
public:
    bool operator()(ListNode * a, ListNode * b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode head, *tmp = &head;
    std::priority_queue<ListNode*, vector<ListNode*>, compare> qq;
    for(int i = 0; i < lists.size(); ++i) {
        if(lists[i] != nullptr) {
            qq.push(lists[i]);
        }
    }

    while(!qq.empty()) {
        tmp -> next = qq.top();
        tmp = tmp -> next;
        qq.pop();
        if(tmp->next) {
            qq.push(tmp->next);
        }
    }

    return head.next;
}


struct cmp{
    bool operator()(const ListNode* a, const ListNode*b) {
        return a->val > b->val;
    }
};


ListNode* mergeKLists1(vector<ListNode*>& lists) {
    ListNode oHead, *pTmp = &oHead;
    priority_queue<ListNode*, std::vector<ListNode*>, cmp> oPriorityQue;
    for(auto pPtr : lists) {
        if(pPtr != nullptr) {
            oPriorityQue.push(pPtr);
        }
    }

    while(!oPriorityQue.empty()) {
        ListNode* pNode = oPriorityQue.top();
        oPriorityQue.pop();
        pTmp->next = pNode;
        pTmp = pNode;
        if(pNode->next) {
            oPriorityQue.push(pNode->next);
        }
    }

    return oHead.next;
}