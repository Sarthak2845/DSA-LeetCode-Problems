class Solution {
public:
    void buildLPS(string &pat, vector<int> &LPS) {
        int len = 0, i = 1;

        while (i < pat.size()) {
            if (pat[i] == pat[len]) {
                LPS[i] = ++len;
                i++;
            } else {
                if (len != 0) {
                    len = LPS[len - 1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }
    bool KMP(string &txt, string &pat){
        int n=txt.size();
        int m=pat.size();
        vector<int> LPS(m, 0);
        buildLPS(pat, LPS);
        int i = 0, j = 0;
        while(i<n){
            if(txt[i]==pat[j]){
                i++;
                j++;
            }
            if(j==m) return true;
            if (i < n && txt[i] != pat[j]) {
                if (j != 0) j = LPS[j - 1];
                else i++;
            }
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        string repeated=a;
        int cnt=1;
        while(repeated.size()<b.size()){
            repeated+=a;
            cnt++;
        }
        if(KMP(repeated,b)) return cnt;
        repeated+=a;
        cnt++;
        if(KMP(repeated,b)) return cnt;
        return -1;
    }
};