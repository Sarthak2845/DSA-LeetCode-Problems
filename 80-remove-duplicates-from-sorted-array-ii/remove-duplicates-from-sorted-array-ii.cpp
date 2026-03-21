class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int prev = nums[0];
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (prev == nums[i]) {
                if (cnt < 2) {
                    cnt++;
                } else {
                    nums[i] = INT_MAX; 
                }
            } else {
                prev = nums[i];
                cnt = 1;
            }
        }

        int k = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != INT_MAX) {
                nums[k++] = nums[i];
            }
        }

        return k;
    }
};