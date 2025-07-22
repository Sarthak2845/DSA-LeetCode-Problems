class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int>seen;
        int left=0;
        int curr=0,maxi=INT_MIN;
        for(int right=0;right<nums.size();right++){
            while(seen.count(nums[right])){
                seen.erase(nums[left]);
                curr-=nums[left];
                left++;
            }
            seen.insert(nums[right]);
            curr+=nums[right];
            maxi=max(curr,maxi);
        }
        return maxi;
    }
};