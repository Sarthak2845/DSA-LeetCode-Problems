class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int sz = s.size();
        int pvt = -1;
        for (int i = sz - 2; i >= 0; i--) {
            if (s[i] < s[i + 1]) {
                pvt = i;
                break;
            }
        }
        if (pvt == -1) {
            return -1;
        }
        for (int i = sz - 1; i >= 0; i--) {
            if (s[i] > s[pvt]) {
                swap(s[i], s[pvt]);
                break;
            }
        }
        reverse(s.begin() + pvt + 1, s.end());
        long long ans = stoll(s);
        return (ans > INT_MAX) ? -1 : (int)ans;
    }
};