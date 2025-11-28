class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long curr = 0, best = 0;

        int left = 0;

        for (int right = 0; right < nums.size(); right++) {

            // add element to window
            curr += nums[right];
            freq[nums[right]]++;

            // shrink if window > k
            if (right - left + 1 > k) {
                curr -= nums[left];
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) freq.erase(nums[left]);
                left++;
            }

            if (right - left + 1 == k) {
                if (freq.size() == k) {
                    best = max(best, curr);
                }
            }
        }

        return best;
    }
};
