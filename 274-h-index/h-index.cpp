class Solution {
public:
 int hIndex(vector<int> &citations) {
    int n = citations.size();
    vector<int> freq(n + 1, 0);

    for (int c : citations) {
        if (c >= n) freq[n]++;
        else freq[c]++;
    }

    int s = 0;
    for (int idx = n; idx >= 0; idx--) {
        s += freq[idx];
        if (s >= idx) return idx;
    }

    return 0;
}

};