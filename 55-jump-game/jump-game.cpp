class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable=0;
        int n =nums.size();
        for(int i=0;i<n;i++){
            if(reachable<i) return false;
            reachable=max(reachable,nums[i]+i);
        }
        return true;
    }
};