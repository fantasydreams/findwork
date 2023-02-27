#include <cmath>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    Solution(ListNode* head) {
        len = 0;
        m_head = head;
        while(head) {
            ++len;
            head = head->next;
        }

        srand(time(NULL));
    }
    
    int getRandom() {
        int pos = rand() % len;
        int ans = m_head->val;
        ListNode * tmp = m_head;
        while(pos) {
            --pos;
            ans = tmp -> val;
            tmp = tmp -> next;
        }

        return ans;
    }
private:
    int len;
    ListNode * m_head;
};


class Solution1 {
public:
    Solution1(ListNode* head) {
        m_head = head;
        srand(time(NULL));
    }
    
    int getRandom() {
        int i = 2;
        ListNode * tmp = m_head -> next;
        int ans = m_head->val;
        while(tmp) {
            if((rand() % i) == 0) {
                ans = tmp -> val;
            }
            tmp = tmp -> next;
            ++i;
        }
        
        return ans;
    }
private:
    ListNode * m_head;
};