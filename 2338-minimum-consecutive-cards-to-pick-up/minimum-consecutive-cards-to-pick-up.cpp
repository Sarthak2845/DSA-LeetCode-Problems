class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int>lastI;
        int minL=INT_MAX;
        for(int i=0;i<cards.size();i++){
            if(lastI.count(cards[i])){
                int length = i - lastI[cards[i]] + 1;
                minL=min(minL,length);
            }
            lastI[cards[i]] = i;
        }
         return (minL == INT_MAX) ? -1 : minL;
    }
};