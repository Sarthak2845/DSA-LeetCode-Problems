class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long N=grid.size()*grid.size();
        long long sn=(N*(N+1)/2);
        long long s2n=(N*(N+1)*(2*N+1))/6;
        long long s=0,s2=0;
        for(auto& row : grid){
            for(int val:row){
                s+=val;
                s2+=(long long)val*(long long)val;
            }
        }
        long long val1=s-sn;
        long long val2=s2-s2n;
        val2=val2/val1;
        long long x=(val1+val2)/2;
        long long y=x-val1;
        return {(int)x,(int) y};
    }
};