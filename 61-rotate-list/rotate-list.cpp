/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode* temp = head;
        int len = 1;
        while (temp->next) {
            temp = temp->next;
            len++;
        }
        temp->next = head;
        k %= len;
        int stepsToNewHead = len - k;
        temp = head;
        for (int i = 0; i < stepsToNewHead - 1; i++) {
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = nullptr;
        return newHead;
    }
};
