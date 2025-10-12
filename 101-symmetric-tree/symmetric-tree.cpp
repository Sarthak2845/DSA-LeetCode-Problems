/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool isMirror(TreeNode* n1, TreeNode* n2){
        // Both nodes are NULL → mirror
        if(n1 == NULL && n2 == NULL) {
            return true;
        }
        // One node is NULL, the other is not → not mirror
        if(n1 == NULL || n2 == NULL) {
            return false;
        }
        // Node values are different → not mirror
        if(n1->val != n2->val) {
            return false;
        }
        // Recursively check left-right and right-left
        if(isMirror(n1->left, n2->right) && isMirror(n1->right, n2->left)) {
            return true;
        } else {
            return false;
        }
    }

public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isMirror(root->left, root->right);
    }
};
