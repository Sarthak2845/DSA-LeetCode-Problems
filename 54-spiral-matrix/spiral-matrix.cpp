class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int srow=0,scol=0,erow=m-1,ecol=n-1;
        vector<int>ans;
        while(srow<=erow && scol<=ecol){
            //top
            for(int j=scol;j<=ecol;j++){
                ans.push_back(matrix[srow][j]);
            }
            //right
            for(int j=srow+1;j<=erow;j++){
                ans.push_back(matrix[j][ecol]);
            }
            //bottom
            for(int j=ecol-1;j>=scol;j--){
                if(srow==erow) break;
                ans.push_back(matrix[erow][j]);
            }
            //left
            for(int j=erow-1;j>srow;j--){
                if(scol==ecol) break;
                ans.push_back(matrix[j][scol]);
            }
            srow++;scol++;
            erow--;ecol--;
        }
        return ans;
    }
};