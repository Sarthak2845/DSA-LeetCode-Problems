class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
         int maxCount = 0, currentCount = 0;

    for (int num : nums) {
        if (num == 1) {
            currentCount++;              // count consecutive 1's
            maxCount = max(maxCount, currentCount);
        } else {
            currentCount = 0;            // reset when 0 is found
        }
    }

    return maxCount;
    }
};