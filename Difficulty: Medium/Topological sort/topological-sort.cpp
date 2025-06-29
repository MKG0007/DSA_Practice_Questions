class Solution {
  public:
  
  void dfs(unordered_map<int , vector<int>>& adj , vector<int>&vis , stack<int> &q , int node){
      vis[node] = 1;
      
      for(int ele : adj[node]){
          if(!vis[ele]){
              dfs(adj , vis , q , ele);
          }
      }
      
        q.push(node);
      
  }
    vector<int> topoSort(int v, vector<vector<int>>& edges) {
        unordered_map<int , vector<int>> adj;
        vector<int> vis(v , 0);
        stack<int> q;
        vector<int> ans;
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
        }
        
        for(int i = 0 ; i<v ; i++){
            if(!vis[i]){
                dfs(adj , vis , q ,  i);
            }
        }
        while(!q.empty()){
            ans.push_back(q.top());
            q.pop();
        }
        
        return ans;
    }
};