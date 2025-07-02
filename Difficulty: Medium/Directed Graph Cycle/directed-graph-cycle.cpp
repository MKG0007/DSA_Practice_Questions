class Solution {
  public:
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        unordered_map<int , vector<int>> adj;
        vector<int> in(V , 0);
        queue<int> q;
        for(auto ele : edges){
            int u = ele[0];
            int v = ele[1];
            
            adj[u].push_back(v);
            in[v]++;
        }
        
        for(int i = 0 ; i<V ; i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            
            for(int i : adj[node]){
                in[i]--;
                if(in[i] == 0){
                    q.push(i);
                }
            }
        }
        
        if(ans.size() == V) return false;
        
        return true;
        
        
    
        
        
        
    }
};