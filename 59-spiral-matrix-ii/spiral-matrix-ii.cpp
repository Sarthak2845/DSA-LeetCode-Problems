class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n, vector<int>(n, 0));
        int srow=0,scol=0,erow=n-1,ecol=n-1;
        int num=1;
        while(srow<=erow && scol<=ecol){
            for(int j=scol;j<=ecol;j++){
                matrix[srow][j]=num++;
            }
            //right
            for(int j=srow+1;j<=erow;j++){
                matrix[j][ecol]=num++;
            }
            //bottom
            for(int j=ecol-1;j>=scol;j--){
                if(srow==erow) break;
                matrix[erow][j]=num++;
            }
            //left
            for(int j=erow-1;j>srow;j--){
                if(scol==ecol) break;
                matrix[j][scol]=num++;
            }
            srow++;scol++;
            erow--;ecol--;
        }
        return matrix;
    }
};