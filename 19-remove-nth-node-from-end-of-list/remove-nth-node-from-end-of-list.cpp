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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        if (fast == nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* slow = head;
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return head;
    }
};