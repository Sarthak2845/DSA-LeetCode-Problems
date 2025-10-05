class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int maxSum = INT_MIN;
        int level = 1;   
        int ansLevel = 1;   

        while (!q.empty()) {
            int sum = 0;
            int n = q.size();

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (sum > maxSum) {
                maxSum = sum;
                ansLevel = level;
            }

            level++; 
        }

        return ansLevel;
    }
};
