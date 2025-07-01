class Solution {
  public:
  
    bool bfs(unordered_map<int ,vector<int>> &adj  , vector<int> &vis , int node){
        vis[node] = 1;
        queue<pair<int , int>> q;
        q.push({node , -1});
        while(!q.empty()){
            auto n = q.front();
            q.pop();
            
            for(int ele : adj[n.first]){
                if(!vis[ele]){
                    vis[ele] = 1;
                    q.push({ele , n.first});
                }
                else if(n.second != ele){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        unordered_map<int , vector<int>> adj;
        
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            
        }
        vector<int> vis(V , 0);
        for(int i = 0 ; i<V ; i++){
            if(!vis[i]){
                if(bfs(adj , vis , i) == true) return true;
            }
        }
        
        return false;
        
        
        
        
    }
};