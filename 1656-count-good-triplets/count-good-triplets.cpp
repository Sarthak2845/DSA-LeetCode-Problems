class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    int f=abs(arr[i]-arr[j]);
                    int s=abs(arr[j]-arr[k]);
                    int t=abs(arr[i]-arr[k]);
                    if(f<=a && s<=b && t<=c){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};