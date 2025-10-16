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
    unordered_map<long long, int> prefix{{0 , 1}};
    int dfs(TreeNode* node, long long curr, int target) {
        if (!node) return 0;
        curr += node->val;
        int count = prefix[curr - target];
        ++prefix[curr];
        count += dfs(node->left, curr, target) + dfs(node->right, curr, target);
        --prefix[curr];
        return count;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        return dfs(root, 0, targetSum);
    }
};
