class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        while (true) {
            bool found = false;

            for (int x : nums) {
                if (x == original) {
                    original *= 2;
                    found = true;
                    break;
                }
            }

            if (!found) break;
        }

        return original;
    }
};
