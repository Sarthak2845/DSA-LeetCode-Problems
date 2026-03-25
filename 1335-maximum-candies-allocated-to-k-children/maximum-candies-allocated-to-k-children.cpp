class Solution {
public:
    bool isPossible(vector<int>& candies, int mid, long long k){
        long long cnt=0;
        for(int c:candies){
            cnt+=c/mid;
            if(cnt>=k) return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        sort(candies.begin(),candies.end());
        int left=1;
        int right=*max_element(candies.begin(),candies.end());
        int ans=0;
        while(left<=right){
            int mid=(left+right)/2;
            if(isPossible(candies,mid,k)){
                ans=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
    }
};