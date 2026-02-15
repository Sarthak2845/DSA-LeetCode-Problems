class Solution {
public:
     bool isValid(vector<vector<char>> &mat,int d,int row,int col){
        for(int i=0;i<9;i++){
            if(mat[i][col]==d) return false;
            if(mat[row][i]==d) return false;
        }
        int start_i=row/3*3;
        int start_j=col/3*3;
        for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
                if(mat[start_i+k][start_j+l]==d) return false;
            }
        }
        return true;
    }
        bool solve(vector<vector<char>> &mat){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(mat[i][j]=='.'){
                   for(int d='1';d<='9';d++){
                       if(isValid(mat,d,i,j)){
                           mat[i][j]=d;
                           if(solve(mat)) return true;
                           mat[i][j]='.';
                       }
                   }
                   return false;
                }
                
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& mat) {
         solve(mat);
    }
};