#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void solve(string curr, string &ans, int n, int k, int &cnt) {
        if (curr.size() == n) {
            cnt++;
            if (cnt == k) {
                ans = curr;
            }
            return;
        }
        if (cnt >= k) return;

        for (char c : {'a', 'b', 'c'}) {
            if (curr.empty() || curr.back() != c) {
                solve(curr + c, ans, n, k, cnt);  
            }
        }
    }

    string getHappyString(int n, int k) {
        string ans = "";
        int cnt = 0;
        solve("", ans, n, k, cnt);
        return ans;
    }
};