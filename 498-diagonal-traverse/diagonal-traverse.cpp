class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int, vector<int>> mp;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mp[i + j].push_back(mat[i][j]);
            }
        }
        vector<int> ans;
        for (auto it : mp) {
            if (it.first % 2 != 0) {
                for (int p : it.second) {
                    ans.push_back(p);
                }
            }
            else{
                for(int i=it.second.size()-1;i>=0;i--){
                    ans.push_back(it.second[i]);
                }
            }
        }
        return ans;
    }
};