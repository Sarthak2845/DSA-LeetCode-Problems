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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>matrix(m, vector<int>(n, -1));
        ListNode* temp=head;
        int srow=0,scol=0,erow=m-1,ecol=n-1;
        int num=1;
        while(srow<=erow && scol<=ecol){
            for(int j=scol;j<=ecol && temp;j++){
                matrix[srow][j]=temp->val;
                temp=temp->next;
            }
            //right
            for(int j=srow+1;j<=erow && temp;j++){
                matrix[j][ecol]=temp->val;
                temp=temp->next;
            }
            //bottom
            for(int j=ecol-1;j>=scol && temp;j--){
                if(srow==erow) break;
                matrix[erow][j]=temp->val;
                temp=temp->next;
            }
            //left
            for(int j=erow-1;j>srow &&temp;j--){
                if(scol==ecol) break;
                matrix[j][scol]=temp->val;
                temp=temp->next;
            }
            srow++;scol++;
            erow--;ecol--;
        }
        return matrix;
    }
};