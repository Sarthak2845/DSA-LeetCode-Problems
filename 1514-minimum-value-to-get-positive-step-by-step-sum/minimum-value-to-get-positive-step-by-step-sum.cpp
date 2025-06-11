class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minSum=0,sum=0;
        for(int num:nums){
            sum+=num;
            minSum=min(minSum,sum);
        }
        return max(1,1-minSum);
    }
};