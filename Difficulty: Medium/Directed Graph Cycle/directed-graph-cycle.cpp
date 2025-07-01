class Solution {
  public:
  
    bool checkByDfs( unordered_map<int , vector<int>> &adj , vector<int> &vis , vector<int> &path , int node){
        vis[node] = 1;
        path[node] = 1;
        
        for(int ele : adj[node]){
            if(!vis[ele]){
                if(checkByDfs(adj , vis , path , ele)) return true;
            }
            else if(path[ele] == 1) return true;
        }
        path[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        unordered_map<int , vector<int>> adj;
        for(auto ele : edges){
            int u = ele[0];
            int v = ele[1];
            
            adj[u].push_back(v);
        }
        
        vector<int> vis(V , 0);
        vector<int> path(V , 0);
        
        for(int i = 0 ; i<V ; i++){
            if(!vis[i]){
                if(checkByDfs(adj , vis , path , i)) return true;
            }
        }
        
        return false;
        
    }
};