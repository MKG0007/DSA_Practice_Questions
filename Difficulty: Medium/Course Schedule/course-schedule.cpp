class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> pre) {
        unordered_map<int , vector<int>> adj;
        vector<int> in(n , 0);
        queue<int> q;
        for(auto p : pre){
            int u = p[0];
            int v = p[1];
            adj[v].push_back(u);
            in[u]++;
        }
        
        for(int i = 0 ; i<n ; i++){
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
                if(in[i] == 0) q.push(i);
            }
        }
        
        if(ans.size() == n){
            return ans;
        }
        return {};
    }
};