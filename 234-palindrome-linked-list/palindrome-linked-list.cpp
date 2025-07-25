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
    stack<int>st;
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        while(temp!=nullptr){
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp!=nullptr){
            if(temp->val==st.top()){
                st.pop();
                temp=temp->next;
            }
            else{
                return false;
            }
        }
        return true;
    }
};