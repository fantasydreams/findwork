#include "148.SortList.h"
#include <queue>
#include <vector>

class cmp {
public:
    bool operator()(ListNode * a, ListNode *b) {
        return a->val > b->val;
    }
};

ListNode* sortList(ListNode* head) {
    std::priority_queue<ListNode*, std::vector<ListNode *>, cmp> que;
    while(head != nullptr) {
        que.push(head);
        head = head -> next;
    }

    ListNode oHead, *tmp=&oHead;
    while(!que.empty()) {
        tmp -> next = que.top();
        que.pop();
        tmp = tmp -> next;
    }
    tmp -> next = nullptr;

    return oHead.next;
}

ListNode* mergeList(ListNode* a, ListNode* b) {
    ListNode oHead, *tmp = &oHead;
    while(a && b) {
        if(a ->val < b->val) {
            tmp->next = a;
            a = a->next;
        }else {
            tmp->next = b;
            b = b -> next;
        }
        tmp = tmp->next;
    }

    if(a) {
        tmp -> next = a;
    }
    if(b) {
        tmp -> next = b;
    }
    return oHead.next;
}

ListNode* sortListMergeSort(ListNode* head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode * slow = head, *fast = head, *tmp;
    while(fast && fast->next) {
        tmp = slow;
        slow = slow->next;
        fast = fast -> next -> next;
    }
    tmp ->next = nullptr;
    ListNode * left = sortListMergeSort(head);
    ListNode * right = sortListMergeSort(slow);
    return mergeList(left, right);
}