class Solution {
public:
    int kadaneMin(vector<int>& nums,int n){
        int sum=nums[0];
        int mini=nums[0];
        for(int i=1;i<n;i++){
            sum=min(nums[i]+sum,nums[i]);
            mini=min(sum,mini);
        }
        return mini;
    }
    int kadaneMax(vector<int>& nums,int n){
        int sum=nums[0];
        int maxi=nums[0];
        for(int i=1;i<n;i++){
            sum=max(nums[i]+sum,nums[i]);
            maxi=max(sum,maxi);
        }
        return maxi;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int total=accumulate(nums.begin(), nums.end(), 0);
        int minSum=kadaneMin(nums,n);
        int maxSum=kadaneMax(nums,n);
        int circular_sum=total-minSum;
        if(maxSum>0) return max(maxSum,circular_sum);
        return maxSum;
    }
};