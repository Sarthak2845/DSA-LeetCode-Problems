class Solution {
public:
    bool solve(vector<vector<char>>& board, string& word,
               int i, int j, int idx,
               vector<vector<bool>>& vis) {

        if (idx == word.size())
            return true;

        if (i < 0 || j < 0 || 
            i >= board.size() || j >= board[0].size() ||
            vis[i][j] || board[i][j] != word[idx])
            return false;

        vis[i][j] = true;

        bool found = solve(board, word, i - 1, j, idx + 1, vis) ||
                     solve(board, word, i + 1, j, idx + 1, vis) ||
                     solve(board, word, i, j - 1, idx + 1, vis) ||
                     solve(board, word, i, j + 1, idx + 1, vis);

        vis[i][j] = false;  // backtrack

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (solve(board, word, i, j, 0, vis))
                        return true;
                }
            }
        }
        return false;
    }
};
