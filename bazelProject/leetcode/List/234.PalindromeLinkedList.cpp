#include "234.PalindromeLinkedList.h"

bool isPalindrome(ListNode* head) {
    if(head == nullptr) {
        return true;
    }

    ListNode * fast = head, * slow = head;
    while(fast && fast->next && fast -> next ->next) {
        slow = slow->next;
        fast = fast->next;
        if(fast) {
            fast = fast -> next;
        }
    }

    //slow后面的进行反转
    ListNode * left = slow;
    if(slow) {
        ListNode * tmp = slow -> next, *next;
        left ->next = nullptr;
        while(tmp) {
            next = tmp->next;
            tmp -> next = left -> next;
            left -> next = tmp;
            tmp = next;
        }
    }

    // printList(head);
    if(left) {
        left = left->next;
    }
    
    while(head && left) {
        if(head->val != left -> val) {
            return false;
        }
        head = head->next;
        left = left->next;
    }

    return true;
}


bool isPalindrome1(ListNode* head) {
        if(head == nullptr) {
            return true;
        } 

        ListNode* pFast = head, * pSlow = head;
        ListNode* pPre;
        while(pSlow) {
            pPre = pFast;
            pFast = pFast->next;
            pSlow = pSlow->next;
            if(pSlow) {
                pSlow = pSlow->next;
            }
        }

        ListNode* pNode = nullptr;
        while(pFast) {
            ListNode* tmp = pFast;
            pFast = pFast->next;
            tmp->next = pNode;
            pNode = tmp;
        }
        pPre->next = pNode;

        // printList(head);
        // if(pNode) {
        //     printf("mid start %d\n", pNode->val);
        // }

        ListNode* pLink = head;
        while(pNode) {
            if(pLink->val != pNode->val) {
                return false;
            }
            pNode = pNode->next;
            pLink = pLink->next;
        }

        return true;
    }