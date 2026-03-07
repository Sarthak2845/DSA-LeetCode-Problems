class Solution {
public:
    int tellCnt(int n){
        if(n<10) return 1;
        int cnt=0;
        while(n>0){
            n=n/10;
            cnt++;
        }
        return cnt;
    }
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int n:nums){
            if( tellCnt(n)%2==0) ans++;
        }
        return ans;
    }
};