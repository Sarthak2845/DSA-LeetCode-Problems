class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (m > n) return "";

        vector<int> hash(256, 0);
        for (char c : t) hash[c]++;

        int count = m;  
        int l = 0, r = 0;
        int minLen = INT_MAX, start = 0;

        while (r < n) {
            if (hash[s[r]] > 0)
                count--;
            hash[s[r]]--; 
            r++;

            while (count == 0) { 
                if (r - l < minLen) {
                    minLen = r - l;
                    start = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) count++; 
                l++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
