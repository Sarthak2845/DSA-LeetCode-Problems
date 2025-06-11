class Solution {
public:
    int maxScore(string s) {
        int totalOnes = 0;
        for (char c : s) {
            if (c == '1') totalOnes++;
        }

        int maxScore = 0, leftZeros = 0, rightOnes = totalOnes;

        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '0') leftZeros++;
            else rightOnes--;

            maxScore = max(maxScore, leftZeros + rightOnes);
        }

        return maxScore;
    }
};
