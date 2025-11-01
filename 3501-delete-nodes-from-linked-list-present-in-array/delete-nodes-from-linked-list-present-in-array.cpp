class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());

        while (head && s.count(head->val)) {
            head = head->next;
        }

        if (!head) return nullptr;

        ListNode* curr = head;
        while (curr->next) {
            if (s.count(curr->next->val)) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};
