class Solution {
public:
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(prev) prev->next = NULL;
        return slow;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;

        ListNode* mid = findMid(head);
        TreeNode* root = new TreeNode(mid->val);

        // base case: single node
        if(head == mid) return root;

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);

        return root;
    }
};