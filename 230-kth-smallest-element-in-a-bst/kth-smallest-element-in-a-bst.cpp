class Solution {
public:
    int solve(TreeNode* root, int& cnt, int k) {
        if (!root) return -1;
        int left = solve(root->left, cnt, k);
        if (left != -1) return left;
        cnt++;
        if (cnt == k) return root->val;
        return solve(root->right, cnt, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        return solve(root, cnt, k);
    }
};