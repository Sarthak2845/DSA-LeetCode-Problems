class Solution {
public:
vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    sort(potions.begin(), potions.end());
    int n = potions.size();
    vector<int> ans;

    for (long long s : spells) {
        long long needed = (success + s - 1) / s;  // ceil division

        auto it = lower_bound(potions.begin(), potions.end(), needed);
        ans.push_back(n - (it - potions.begin()));
    }

    return ans;
}

};