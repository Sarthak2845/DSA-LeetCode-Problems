class Solution {
public:
    int solve(string &s, int l, int r){
        int cnt = 0;
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            cnt++;
            l--;
            r++;
        }
        return cnt;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;

        for(int i = 0; i < n; i++){
            res += solve(s, i, i);    
            res += solve(s, i, i + 1); 
        }

        return res;
    }
};