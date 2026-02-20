class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<nums.size() && n>0 ;i++){
            if(nums[i]*(n-1)>sum-nums[i]){
                cnt++;
            }
            sum-=nums[i];
            n--;
        }
        return cnt;
    }
};