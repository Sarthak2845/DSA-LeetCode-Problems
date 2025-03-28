class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false; 

        vector<int> s1freq(26, 0), winfreq(26, 0);

        
        for (int i = 0; i < s1.size(); i++) {
            s1freq[s1[i] - 'a']++;
            winfreq[s2[i] - 'a']++;  
        }

        
        if (s1freq == winfreq) return true;

     
        for (int i = s1.size(); i < s2.size(); i++) {
            winfreq[s2[i] - 'a']++;         
            winfreq[s2[i - s1.size()] - 'a']--; 

            if (s1freq == winfreq) return true; 
        }

        return false;
    }
};