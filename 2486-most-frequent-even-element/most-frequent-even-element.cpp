class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                freq[nums[i]]++;
            }
        }
         int maxFreq = 0, result = -1;
         for (auto it : freq) {
            if(it.second>maxFreq){
                maxFreq=it.second;
                result=it.first;
            }
         }
         return result;
    }
};