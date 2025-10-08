class Solution {
public:
    bool checkValid(vector<vector<int>>& mat) {
        int n = mat.size();
        
        for (int i = 0; i < n; i++) {
            unordered_set<int> rowSet;
            unordered_set<int> colSet;
            
            for (int j = 0; j < n; j++) {
                if (rowSet.count(mat[i][j])) return false;
                rowSet.insert(mat[i][j]);
                if (colSet.count(mat[j][i])) return false;
                colSet.insert(mat[j][i]);
            }
        }
        return true;
    }
};
