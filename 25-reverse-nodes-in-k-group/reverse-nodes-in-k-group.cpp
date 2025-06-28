class Solution {
public:
    ListNode* getKNode(ListNode* temp, int k) {
        k -= 1;
        while (temp != nullptr && k > 0) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = nullptr;
        ListNode* newHead = nullptr;

        while (temp != nullptr) {
            ListNode* kthNode = getKNode(temp, k);
            if (!kthNode) {
                if (prevLast) prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr;

            ListNode* reversedHead = reverse(temp); // fix: capture the new head
            if (!newHead) newHead = reversedHead;   // fix: update final head once

            if (prevLast) prevLast->next = reversedHead;

            prevLast = temp;   // fix: 'temp' becomes tail after reverse
            temp = nextNode;
        }

        return newHead ? newHead : head;
    }
};
