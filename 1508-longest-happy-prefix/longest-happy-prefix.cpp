class Solution {
public:
    void buildLPS(string s,vector<int>&LPS){
        int len=0,i=1;
        while(i<s.size()){
            if(s[i]==s[len]){
                len++;
                LPS[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=LPS[len-1];
                }
                else{
                    i++;
                }
            }
        }
    }
    string longestPrefix(string s) {
        int n=s.size();
        vector<int>LPS(n,0);
        buildLPS(s,LPS);
        return s.substr(0,LPS.back());
    }
};