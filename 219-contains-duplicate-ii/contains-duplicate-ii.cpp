class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            if(mpp.count(nums[i]) && i-mpp[nums[i]]<=k){
                return true;
            }
             mpp[nums[i]] = i;
        }
        return false;
    }
};