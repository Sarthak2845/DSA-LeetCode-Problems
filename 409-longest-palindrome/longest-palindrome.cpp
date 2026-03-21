class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int>freq;
        for(char c:s){
            freq[c]++;
        }
        int len=0;
        bool oddFound=false;
        for(auto& p: freq){
            int cnt=p.second;
            len+=(cnt/2)*2;
            if(cnt%2==1){
                oddFound=true;
            }
        }
        if(oddFound) len+=1;
        return len;
    }
};