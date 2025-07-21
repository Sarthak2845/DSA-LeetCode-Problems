class Solution {
public:
    int maxProduct(vector<int>& nums) {
    if (nums.empty()) return 0;

    int maxProd = nums[0];
    int minProd = nums[0];
    int result = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        int num = nums[i];

        if (num < 0) {
            swap(maxProd, minProd); 
        }

        maxProd = max(num, num * maxProd);
        minProd = min(num, num * minProd);

        result = max(result, maxProd);
    }

    return result;


    }
};