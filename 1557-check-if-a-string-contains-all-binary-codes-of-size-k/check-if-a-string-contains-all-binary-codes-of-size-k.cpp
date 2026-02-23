class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) return false;

        unordered_set<string> seen_codes;
        
        for (int i = 0; i <= (int)s.size() - k; i++) {
            seen_codes.insert(s.substr(i, k));
        }
        
        return seen_codes.size() == (1 << k);
    }
};
