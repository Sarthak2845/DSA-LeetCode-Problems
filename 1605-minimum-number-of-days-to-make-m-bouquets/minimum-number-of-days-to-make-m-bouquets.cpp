class Solution {
public:
    // Check if we can make m bouquets by day 'days'
    bool canMake(vector<int>& bloomDay, int m, int k, int days) {
        int bouquets = 0, flowers = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= days) {
                flowers++; // flower has bloomed
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0; // break the chain
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowers = 1LL * m * k;
        if (bloomDay.size() < totalFlowers) return -1; // impossible

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canMake(bloomDay, m, k, mid)) {
                ans = mid;      // maybe this day works
                high = mid - 1; // try earlier
            } else {
                low = mid + 1;  // too early
            }
        }

        return ans;
    }
};
