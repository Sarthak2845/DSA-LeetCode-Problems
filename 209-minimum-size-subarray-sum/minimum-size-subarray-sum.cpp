class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0, sum = 0;
        int minIdx = INT_MAX;

        for (int high = 0; high < nums.size(); ++high) {
            sum += nums[high];

            while (sum >= target) {
                minIdx = min(minIdx, high - low + 1);
                sum -= nums[low];
                ++low;
            }
        }

        return (minIdx == INT_MAX) ? 0 : minIdx;
    }
};
