class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int totalSum=accumulate(arr.begin(),arr.end(),0);
        if(totalSum%3!=0) return false;
        int target=totalSum/3;
        int first=-1, second=-1;
        int currSum=0;
        for(int i=0;i<arr.size();i++){
            currSum+=arr[i];
            if(currSum==target && first==-1) first=i;
            else if(currSum==2*target && second==-1  && first != -1 && i < arr.size() - 1) second=i;
        }
        if(first!=-1 && second!=-1) return true;
        return false;
    }
};