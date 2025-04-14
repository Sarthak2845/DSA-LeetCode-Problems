class Solution {
public:
    int check(vector<int>& nums, int divisor) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] + divisor - 1) / divisor;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int sum = check(nums, mid);
            
            if (sum > threshold) {
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }

        return low; 
    }
};
