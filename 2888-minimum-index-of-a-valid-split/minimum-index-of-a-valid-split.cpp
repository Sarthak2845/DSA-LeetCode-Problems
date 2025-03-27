class Solution {
    int votingAlgo(vector<int> &nums){
        int el=nums[0];
        int freq=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=el) freq--;
            else freq++;
            if(freq==0){
                el=nums[i];
                freq=1;
            }

        }
        return el;
    }
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        int major=votingAlgo(nums);
        int max_freq=0;
        for(int num:nums){
            if(num==major){
                max_freq++;
            }
        }
        int prefix_cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==major){
                prefix_cnt++;
                max_freq--;
            }
            if((prefix_cnt>(i+1)/2) & (max_freq>(n-i-1)/2)){
                return i;
            }

        }
        return -1;
    }
};