class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int closest = nums[0];
        for (int num : nums) {
            if (abs(num) < abs(closest)) {
                closest = num;
            } else if (abs(num) == abs(closest) && num > closest) {
                closest = num; // prefer positive one if tied
            }
        }
        return closest;
    }
};
