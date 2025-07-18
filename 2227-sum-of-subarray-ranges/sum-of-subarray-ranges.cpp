class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return getSum(nums, true) - getSum(nums, false);
    }

private:
    long long getSum(vector<int>& nums, bool isMax) {
        long long res = 0;
        int n = nums.size();
        stack<int> st;

        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && 
                  (i == n || (isMax ? nums[st.top()] < nums[i] : nums[st.top()] > nums[i]))) {
                int mid = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                long long count = (mid - left) * 1LL * (right - mid);
                res += count * nums[mid];
            }
            st.push(i);
        }
        return res;
    }
};
