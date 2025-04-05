class Solution {
public:
    int dfs(vector<int>& nums, int index, int currentXor) {
        if (index == nums.size()) {
            return currentXor;
        }

        // include nums[index]
        int with = dfs(nums, index + 1, currentXor ^ nums[index]);
        
        // exclude nums[index]
        int without = dfs(nums, index + 1, currentXor);
        
        return with + without;
    }

    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }
};
