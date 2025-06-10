class Solution {
public:
    int maxDifference(string s) {
         unordered_map<char, int> freq;
         for(char ch:s){
            freq[ch]++;
         }
         int maxOdd=INT_MIN;
         int minEven=INT_MAX;
         bool hasE,hasO=false;
         for(auto &[ch,count]:freq){
            if(count%2==1){
                maxOdd=max(count,maxOdd);
                hasO=true;
            }
            else{
                minEven=min(count,minEven);
                hasE=true;
            }
         }
         
    if (!hasO || !hasE) return -1; 
    return maxOdd - minEven;
    }
};