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
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int currSum=0;
        return checkSum(root,targetSum,currSum);
    }
    bool checkSum(TreeNode* root, int targetSum, int currSum){
        if(root==nullptr) return false;
        currSum+=root->val;
        if(root->left==NULL && root->right==NULL){
            return currSum==targetSum;
        }
        return checkSum(root->left,targetSum,currSum) || checkSum(root->right,targetSum,currSum);
    }
};