class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int pos=0;
        int cnt=0;
        for(int num:nums){
            pos+=num;
            if(pos==0) cnt++;
        }
        return cnt;
    }
};