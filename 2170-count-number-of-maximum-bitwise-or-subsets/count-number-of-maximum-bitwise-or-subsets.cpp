class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        for (int x : nums) mx |= x;

        int ans = 0;
        function<void(int,int)> dfs = [&](int i, int cur){
            if (i == n) { ans += (cur == mx); return; }
            dfs(i + 1, cur | nums[i]);   
            dfs(i + 1, cur);            
        };
        dfs(0, 0);
        return ans;
    }
};