class Solution {
public:
   

int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> remainderFreq;
    remainderFreq[0] = 1;  
    int prefixSum = 0, count = 0;
    
    for (int num : nums) {
        prefixSum += num;
        int remainder = prefixSum % k;
        if (remainder < 0)
            remainder += k;

 
        if (remainderFreq.find(remainder) != remainderFreq.end()) {
            count += remainderFreq[remainder];
        }


        remainderFreq[remainder]++;
    }
    
    return count;
}

};