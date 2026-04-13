class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1; // visiting
        
        for(auto neigh : adj[node]){
            if(vis[neigh] == 0){
                if(dfs(neigh, adj, vis)) return true;
            }
            else if(vis[neigh] == 1){
                return true; // cycle found
            }
        }
        
        vis[node] = 2; // done
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(numCourses, 0);

        for(int i = 0; i < numCourses; i++){
            if(vis[i] == 0){
                if(dfs(i, adj, vis)){
                    return false;
                }
            }
        }
        return true;
    }
};