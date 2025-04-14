class Solution {
public:
    bool check(vector<int>& weights,int days,int capacity){
        int reqD=1,weig=0;
        for(int w:weights){
            if(weig+w>capacity){
                reqD++;
                weig=0;
            }
            weig+=w;
        }
        return reqD<=days;
    };

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low<=high){
            int mid=(low+high)/2;
            if(check(weights,days,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};