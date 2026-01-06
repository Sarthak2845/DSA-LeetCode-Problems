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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small=new ListNode(0);
        ListNode* large=new ListNode(0);
        ListNode* smallp=small;
        ListNode* largep=large;
        ListNode* curr=head;
        while(curr){
            if(curr->val<x){
                small->next=curr;
                small=small->next;
            }
            else{
                large->next=curr;
                large=large->next;
            }
            curr=curr->next;
        }
        small->next=largep->next;
        large->next=NULL;
        return smallp->next;

    }
};