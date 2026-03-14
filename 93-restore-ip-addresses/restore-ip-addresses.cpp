class Solution {
public:
    bool isValid(string part){
        if(part.size() > 1 && part[0] == '0') return false;
        int num = stoi(part);
        return num >= 0 && num <= 255;
    }

    void solve(string curr, int idx, int seg, string &s, vector<string>& ans){
        
        if(seg == 4 && idx == s.size()){
            ans.push_back(curr);
            return;
        }

        if(seg == 4 || idx == s.size()) return;

        for(int len = 1; len <= 3; len++){

            if(idx + len > s.size()) break;

            string part = s.substr(idx, len);

            if(!isValid(part)) continue;

            string next = curr.empty() ? part : curr + "." + part;

            solve(next, idx + len, seg + 1, s, ans);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        solve("", 0, 0, s, ans);
        return ans;
    }
};