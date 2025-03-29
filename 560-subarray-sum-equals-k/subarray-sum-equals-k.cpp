class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mpp;
        mpp[0]=1;
        int prefixsum=0,cnt=0;
        for(int i=0;i<nums.size();i++){
            prefixsum+=nums[i];
            int rvm=prefixsum-k;
            cnt+=mpp[rvm];
            mpp[prefixsum]+=1;
        }
        return cnt;
    }
};