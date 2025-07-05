class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int i = 0; i < arr.size(); ++i) {
            freq[arr[i]]++;
        }
        int maxi=-1;
        for(auto it:freq){
            if(it.first==it.second){
                maxi=max(maxi,it.second);
            }
        }
        return maxi;
    }
};