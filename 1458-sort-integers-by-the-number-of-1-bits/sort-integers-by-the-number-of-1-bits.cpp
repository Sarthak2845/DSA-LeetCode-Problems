class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int,vector<int>>mp;
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            int num=arr[i];
            int freq=__builtin_popcount(num);
                mp[freq].push_back(num);
        }
        for(auto &it:mp){
            sort(it.second.begin(),it.second.end());
            for(int i=0;i<it.second.size();i++){
                ans.push_back(it.second[i]);
            }
        }
        return ans;
    }
};