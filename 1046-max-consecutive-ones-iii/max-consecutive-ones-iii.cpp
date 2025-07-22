class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int maxl=0,zc=0;
        while(r<nums.size()){
            if(nums[r]==0) zc++;
            while(zc>k){
                if(nums[l]==0) zc--;
                l++;
            }
            maxl=max(maxl,r-l+1);
            r++;
        }
        return maxl;
    }
};