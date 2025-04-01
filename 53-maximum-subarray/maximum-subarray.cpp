class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentsum=0;
        int Maxsum = INT_MIN;
        for(int val :nums){
            currentsum += val;
            Maxsum = max(currentsum, Maxsum);
            if(currentsum<0)
            currentsum = 0;   
        }
        return Maxsum;
    }
};