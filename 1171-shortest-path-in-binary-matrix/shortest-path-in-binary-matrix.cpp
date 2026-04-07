class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        vector<vector<bool>>visi(n,vector<bool>(n,false));
        queue<pair<pair<int,int>, int>>q;
        q.push({{0,0},1});
        visi[0][0]=true;
        int dx[8]={-1,1,0,0,-1,-1,1,1};
        int dy[8]={0,0,-1,1,-1,1,-1,1};
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            int x=front.first.first;
            int y=front.first.second;
            int step=front.second;
            if(x==n-1 && y==n-1) return step;
            for(int i=0;i<8;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<n && !visi[nx][ny] && grid[nx][ny]==0){
                    visi[nx][ny]=true;
                    q.push({{nx,ny},step+1});
                }
            }
        }
        return -1;
    }
};