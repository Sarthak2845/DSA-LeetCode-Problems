class Solution {
public:
    bool can(vector<int>& price, int mid, int k){
            int cnt=1;
            int last=price[0];
            for(int i=1;i<price.size();i++){
                if(price[i]-last>=mid){
                    cnt++;
                    last=price[i];
                    if(cnt==k) return true;
                }
            }
            return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int l=0;
        int r=price.back()-price.front();
        int ans;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(can(price,mid,k)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};