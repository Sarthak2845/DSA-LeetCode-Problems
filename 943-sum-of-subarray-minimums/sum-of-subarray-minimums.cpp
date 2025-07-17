class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> prevLess(n), nextLess(n);
        stack<int> st;

        // Previous Less Element (strictly greater)
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            prevLess[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear stack to reuse
        while (!st.empty()) st.pop();

        // Next Less Element (greater than or equal)
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nextLess[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long result = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - prevLess[i];
            long long right = nextLess[i] - i;
            result = (result + arr[i] * left % MOD * right % MOD) % MOD;
        }

        return result;
    }
};
