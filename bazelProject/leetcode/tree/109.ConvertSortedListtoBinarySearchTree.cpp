

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