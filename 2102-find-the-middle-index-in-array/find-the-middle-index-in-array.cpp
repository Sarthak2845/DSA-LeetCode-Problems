class Solution {
public:
    int findMiddleIndex(vector<int>& arr) {
        int n=arr.size();
        long long total=accumulate(arr.begin(),arr.end(),0LL);
        long long leftsum=0;
        for(int i=0;i<n;i++){
            long long rightsum=total-leftsum-arr[i];
            if(leftsum==rightsum) return i;
            leftsum+=arr[i];
        }
        return -1;
    }
};