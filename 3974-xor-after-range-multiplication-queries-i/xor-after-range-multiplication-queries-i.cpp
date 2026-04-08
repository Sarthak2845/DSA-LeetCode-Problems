class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();
        int MOD=1e9+7;
        for(int i=0;i<m;i++){
            int idx=queries[i][0];
            int r=queries[i][1];
            int k=queries[i][2];
            int v=queries[i][3];
            while(idx<=r){
                nums[idx]=(1LL*nums[idx]*v)%MOD;
                idx+=k;
            }
        }
        int ans=0;
        for(int x:nums){
            ans^=x;
        }
        return ans;
    }
};