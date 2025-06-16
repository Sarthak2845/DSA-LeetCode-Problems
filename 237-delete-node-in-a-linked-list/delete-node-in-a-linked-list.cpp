class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;       // copy data from next node
        ListNode* temp = node->next;       
        node->next = node->next->next;     // skip over the next node
        delete temp;                       // free memory
    }
};
