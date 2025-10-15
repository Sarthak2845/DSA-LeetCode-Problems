/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> row;
        int currSum = 0;
        checkSum(root, targetSum, currSum, ans, row);
        return ans;
    }
    void checkSum(TreeNode* root, int targetSum, int currSum,
                  vector<vector<int>>& ans, vector<int>& row) {
        if (!root)
            return;
        currSum += root->val;
        row.push_back(root->val);

        if (!root->left && !root->right && currSum == targetSum)
            ans.push_back(row);

        checkSum(root->left, targetSum, currSum, ans, row);
        checkSum(root->right, targetSum, currSum, ans, row);

        row.pop_back();
    }
};