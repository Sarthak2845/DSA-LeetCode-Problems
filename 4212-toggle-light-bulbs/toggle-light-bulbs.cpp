class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int bulb:bulbs){
            mp[bulb]=0;
        }
        for(int bulb:bulbs){
            if(mp[bulb]==0){
                mp[bulb]=1;
            }
            else{
                mp[bulb]=0;
            }
        }
        for(auto it:mp){
            if(it.second==1){
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};