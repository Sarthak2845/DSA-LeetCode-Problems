class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1,sufix=1;
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(prefix==0) prefix=1;
            if(sufix==0) sufix=1;
            prefix=prefix*nums[i];
            sufix=sufix*nums[n-i-1];
            ans=max(ans,max(prefix,sufix));
        }
        return ans;
    }
};