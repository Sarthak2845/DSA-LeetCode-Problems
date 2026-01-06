class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());
        int idx = 0;

        // elements < pivot
        for (int x : nums) {
            if (x < pivot) ans[idx++] = x;
        }

        // elements == pivot
        for (int x : nums) {
            if (x == pivot) ans[idx++] = x;
        }

        // elements > pivot
        for (int x : nums) {
            if (x > pivot) ans[idx++] = x;
        }

        return ans;
    }
};
