class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ls=s.size();
        int lp=p.size();
        vector<int>ans;
        if(ls<lp){
            return ans;
        }
        vector<int>pfreq(26,0),sfreq(26,0);
        for(int i=0;i<lp;i++){
            pfreq[p[i]-'a']++;
            sfreq[s[i]-'a']++;
        }
        if(pfreq==sfreq){
            ans.push_back(0);
        }
        for(int i=lp;i<ls;i++){
            sfreq[s[i]-'a']++;
            sfreq[s[i - lp] - 'a']--;
            if (pfreq == sfreq) ans.push_back(i - lp + 1);
        }

    return ans;
    }
};