class Solution {
  public:
  
    bool check(unordered_map<int , vector<int>> &adj , vector<int> & vis , int node){
        vis[node] = 1;
        
        queue<pair<int , int>> q;
        q.push({node , -1});
        
        while(!q.empty()){
            int ele = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(int i : adj[ele]){
                if(!vis[i]){
                    vis[i] = 1;
                    q.push({i , ele});
                    
                }
                else if(parent != i){
                    return true;
                }
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
                if(check(adj, visited , i)) return true;
            }
        }
        
        return false;
    }
};