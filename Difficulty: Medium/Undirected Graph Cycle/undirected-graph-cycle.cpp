class Solution {
  public:
  
    bool isCheck(unordered_map<int , vector<int>> &adj , int node , vector<int> &visited){
        queue<pair<int , int>> q;
        q.push({node , -1});
        visited[node] = 1;
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(int ele : adj[node]){
                if(!visited[ele]){
                    visited[ele] = 1;
                    q.push({ele , node});
                }
                else if(parent != ele){
                    return true;
                }
            }
        }
        return false;
        
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int , vector<int>> adj;
        for(auto edge : edges){
            int v = edge[0];
            int u = edge[1];
            
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        
        vector<int> visited(V , 0);
        
        for(int i = 0 ; i<V ; i++){
            if(!visited[i]){
            if(isCheck(adj , i , visited)){
                return true;
            }
            }
            
        }
        
        return false;
    }
};