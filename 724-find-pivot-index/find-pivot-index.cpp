class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> sumLeft(n, 0);
        vector<int> sumRight(n, 0);

        // Build sumLeft
        for (int i = 1; i < n; ++i) {
            sumLeft[i] = sumLeft[i - 1] + nums[i - 1];
        }

        for (int i = n - 2; i >= 0; --i) {
            sumRight[i] = sumRight[i + 1] + nums[i + 1];
        }


        for (int i = 0; i < n; ++i) {
            if (sumLeft[i] == sumRight[i]) {
                return i;
            }
        }

        return -1;
    }
};
