#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(int n, int k, int start, vector<vector<int>>& ans, vector<int>& curr) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i <= n; i++) {
            curr.push_back(i);       
            solve(n, k, i + 1, ans, curr); 
            curr.pop_back();        
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(n, k, 1, ans, curr);
        return ans;
    }
};