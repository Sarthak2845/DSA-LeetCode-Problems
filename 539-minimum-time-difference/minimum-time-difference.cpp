class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>M;
        int n=timePoints.size();
        for(int i=0;i<n;i++){
            int hr=stoi(timePoints[i].substr(0,2));
            int mint=stoi(timePoints[i].substr(3,2));
            int total=hr*60+mint;
            M.push_back(total);
        }
        sort(M.begin(),M.end());
        int mini=24*60;
        for(int i=1;i<n;i++){
            int diff=M[i]-M[i-1];
            mini=min(mini,diff);
        }
        int circ_diff=((24*60)+M[0])-M[n-1];
        mini=min(mini,circ_diff);
        return mini;
    }
};