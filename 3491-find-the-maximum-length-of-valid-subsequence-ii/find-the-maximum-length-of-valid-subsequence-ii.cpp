class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 1;

        // map: mod -> list of {index, length of subsequence ending here}
        unordered_map<int, unordered_map<int, int>> last;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int mod = (nums[i] + nums[j]) % k;

                int len = 2; // start new pair
                if (last[mod].count(j)) {
                    len = last[mod][j] + 1; // extend previous
                }

                last[mod][i] = max(last[mod][i], len);
                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};
