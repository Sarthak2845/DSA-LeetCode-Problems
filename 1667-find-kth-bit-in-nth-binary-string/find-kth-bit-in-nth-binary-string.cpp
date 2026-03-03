class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";

        for (int i = 2; i <= n; i++) {
            string t = s;

            for (char& c : t) {
                c = (c == '0') ? '1' : '0';
            }

            reverse(t.begin(), t.end());

            s = s + "1" + t;
        }

        return s[k - 1];
    }
};