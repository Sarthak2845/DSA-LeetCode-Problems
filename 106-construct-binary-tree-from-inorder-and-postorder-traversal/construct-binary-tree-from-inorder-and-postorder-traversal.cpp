class Solution {
public:
    TreeNode* treeHelper(vector<int>& inorder, vector<int>& postorder, int is, int ie, int &postIdx, unordered_map<int,int>& mp) {
        if (is > ie) return nullptr;

        int rootVal = postorder[postIdx];
        TreeNode* root = new TreeNode(rootVal);
        int inRoot = mp[rootVal];
        postIdx--;

        root->right = treeHelper(inorder, postorder, inRoot + 1, ie, postIdx, mp);
        root->left  = treeHelper(inorder, postorder, is, inRoot - 1, postIdx, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) return nullptr;
        int n = inorder.size();
        int postIdx = n - 1;
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        return treeHelper(inorder, postorder, 0, n - 1, postIdx, mp);
    }
};
