class Solution {
public:
    string finalString(string s) {
        string res;
        int idx=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!='i'){
                res+=s[i];
            }
            else{
                reverse(res.begin(),res.end());
            }
        }
        return res;
    }
};