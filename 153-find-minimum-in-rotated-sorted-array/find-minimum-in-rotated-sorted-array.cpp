class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int small=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[low]<=nums[mid]){
                small=min(nums[low],small);
                low=mid+1;
            }
            else{
                small=min(nums[mid],small);
                high=mid-1;
            }
        }
        return small;
    }
};