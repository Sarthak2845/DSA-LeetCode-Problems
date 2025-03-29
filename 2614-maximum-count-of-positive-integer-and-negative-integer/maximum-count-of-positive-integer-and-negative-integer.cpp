class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int negCount = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int posCount = n - (upper_bound(nums.begin(), nums.end(), 0) - nums.begin());
        return max(negCount, posCount);
    }
};