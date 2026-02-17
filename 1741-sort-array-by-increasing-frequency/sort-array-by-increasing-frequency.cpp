class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int,int> freq;
        
        for(int n : nums){
            freq[n]++;
        }

        auto cmp = [](pair<int,int>& a, pair<int,int>& b){
            if(a.first == b.first)
                return a.second < b.second;  // larger number first
            return a.first > b.first;        // smaller freq first
        };

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            decltype(cmp)
        > pq(cmp);

        for(auto it : freq){
            pq.push({it.second, it.first});
        }

        vector<int> res;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            for(int i = 0; i < top.first; i++){
                res.push_back(top.second);
            }
        }

        return res;
    }
};
