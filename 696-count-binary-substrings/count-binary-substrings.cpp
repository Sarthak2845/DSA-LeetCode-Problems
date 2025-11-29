class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int>group(s.size());
        int idx=0;
        group[0]=1;
        for(int i=1;i<s.size();i++){
            if(s[i-1]!=s[i]){
                idx++;
                group[idx]=1;
            }
            else{
                group[idx]++;
            }
        }
        int cnt=0;
        for(int i=1;i<s.size();i++){
            cnt+=min(group[i-1],group[i]);
        }
        return cnt;
    }
};