class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
         int n = weights.size();
    if (k == 1) return 0;  

    vector<int> pairwise;
    
    for (int i = 0; i < n - 1; i++) {
        pairwise.push_back(weights[i] + weights[i + 1]);
    }
    sort(pairwise.begin(), pairwise.end());

    long long min_score = 0, max_score = 0;
    for (int i = 0; i < k - 1; i++) {
        min_score += pairwise[i];                  
        max_score += pairwise[n - 2 - i];         
    }

    return max_score - min_score;
    }
};