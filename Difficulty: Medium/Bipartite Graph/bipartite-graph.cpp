class Solution {
  public:
  bool bfs(unordered_map<int , vector<int>> &adj, vector<int> &vis , int node){
      
      vis[node] = 0;
      
      queue<int> q;
      q.push(node);
      
      while(!q.empty()){
          int i = q.front();
          q.pop();
          
          for(int ele : adj[i]){
              if(vis[ele] == -1){
                  
                  vis[ele] = 1 - vis[i];
                  q.push(ele);
              }
              else if(vis[ele] == vis[i]){
                  return false;
              }
          }
      }
      return true;
  }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        unordered_map<int , vector<int>> adj;
        
        for(auto ele : edges){
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }
        vector<int> vis(V , -1);
        
        for(int i = 0 ; i<V ; i++){
            if(vis[i] == -1){
                if(bfs(adj , vis , i) == false) return false;
            }
        }
        
        
        return true;
    }
};