#include "109.ConvertSortedListtoBinarySearchTree.h"
#include "108.ConvertSortedArraytoBinarySearchTree.h"
#include <vector>
#include "treecomm.h"
using namespace std;

TreeNode* sortedListToBST1(ListNode* head) {
    if(head == nullptr) {
        return nullptr;
    }    

    std::vector<int> vec;
    while(head) {
        vec.push_back(head->val);
        head = head->next;
    }

    return sortedArrayToBST(vec);
}

TreeNode* sortedListToBST(ListNode* head) {
         if(!head) {
             return nullptr;
         }       

         ListNode* slow = head, *fast = head, *pre = nullptr;
         while(fast && fast->next) {
             pre = slow;
             slow = slow->next;
             fast = fast->next->next;
         }

        if(pre) {
            pre->next = nullptr;
        }

        ListNode* right = slow->next;
        slow->next = nullptr;
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head == slow ? nullptr : head);
        root->right = sortedListToBST(right);
        return root;
    }