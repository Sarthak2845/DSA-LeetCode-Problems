class Solution {
public:
    int triangleNumber(vector<int>& arr) {
                int n=arr.size();
        sort(arr.begin(),arr.end());
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            int l=0,r=i-1;
            while(l<r){
                int sum=arr[l]+arr[r];
                if(sum>arr[i]){
                    cnt+=r-l;
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return cnt;
    }
};