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