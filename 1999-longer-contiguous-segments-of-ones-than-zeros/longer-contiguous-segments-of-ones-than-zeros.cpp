class Solution {
public:
    bool checkZeroOnes(string s) {
        int max1 = 0, max0 = 0;
        int curr = 1;
        char prev = s[0];

        for(int i = 1; i < s.size(); i++){
            if(s[i] == prev){
                curr++;
            }
            else{
                if(prev == '1'){
                    max1 = max(max1, curr);
                }
                else{
                    max0 = max(max0, curr);
                }
                curr = 1;
                prev = s[i];
            }
        }

        if(prev == '1'){
            max1 = max(max1, curr);
        }
        else{
            max0 = max(max0, curr);
        }

        return max1 > max0;
    }
};