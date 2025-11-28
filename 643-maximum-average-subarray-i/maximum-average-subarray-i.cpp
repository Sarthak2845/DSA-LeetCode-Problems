class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxi=INT_MIN;
        double sum=0;
        int l=0;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            if(r-l+1>k){
                sum-=nums[l];
                l++;
            }
            if(r-l+1==k){
                maxi=max(sum,maxi);
            }
        }
        return (double)maxi/k;
    }
};