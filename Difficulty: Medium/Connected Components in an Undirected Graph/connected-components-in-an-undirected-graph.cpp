
class Solution {
  public:
  
    void dfs(unordered_map<int , vector<int>> &adj , vector<int> &vis , vector<int> &temp , int node){
        vis[node] = 1;
        temp.push_back(node);
        
        for(int ele : adj[node]){
            if(!vis[ele]){
                dfs(adj , vis , temp , ele);
            }
        }
        
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int , vector<int>> adj;
        vector<vector<int>> ans;
        vector<int> vis(V , 0);
        
        for(auto ele : edges){
            int u = ele[0];
            int v = ele[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        for(int i = 0 ; i<V ; i++){
            if(!vis[i]){
               vector<int> temp;
               dfs(adj , vis , temp , i);
               ans.push_back(temp);
            }
        }
        
        return ans;
        
    }
};
