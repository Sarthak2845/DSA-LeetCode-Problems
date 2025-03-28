class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>sfreq(26,0),tfreq(26,0);
        int ls=s.size();
        int lt=t.size();
        if(ls!=lt) return false;
        for(int i=0;i<ls;i++){
            sfreq[s[i]-'a']++;
        }
        for(int i=0;i<lt;i++){
            tfreq[t[i]-'a']++;
        }
        if(sfreq==tfreq) return true;
        return false;
    }
};