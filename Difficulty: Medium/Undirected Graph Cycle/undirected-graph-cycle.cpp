class Solution {
  public:
  
    bool dfs(unordered_map<int , vector<int>> &adj , vector<int> & vis , int node , int parent){
        vis[node] = 1;
        for(int ele : adj[node]){
            if(!vis[ele]){
                vis[ele] = 1;
                if(dfs(adj , vis , ele , node)) return true;
            }
            else if(parent != ele){
                return true;
            }
            
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int , vector<int>> adj;
        vector<int> visited(V , 0);
        for(auto ele : edges){
            int u = ele[0];
            int v = ele[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i ; i<V ; i++){
            if(!visited[i]){
                if(dfs(adj, visited , i , -1)) return true;
            }
        }
        
        return false;
    }
};