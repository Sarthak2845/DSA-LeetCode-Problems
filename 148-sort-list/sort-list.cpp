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
    ListNode* sortList(ListNode* head) {
        vector<int>arr;
        ListNode* temp=head;
        int i=0;
        while(temp!=nullptr){
            arr.push_back(temp->val);
            i++;
            temp=temp->next;
        }
        sort(arr.begin(),arr.end());
        temp=head;
         i=0;
        while(temp!=nullptr){
            temp->val=arr[i];
            i++;
            temp=temp->next;
        }
        return head;
    }
};