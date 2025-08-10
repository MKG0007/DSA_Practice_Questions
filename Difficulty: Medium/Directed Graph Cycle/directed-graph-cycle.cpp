class Solution {
  public:
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        unordered_map<int , vector<int>> adj;
        
        vector<int> in(V , 0);
        for(auto ele : edges){
            adj[ele[0]].push_back(ele[1]);
            in[ele[1]]++;
        }
        
        
        queue<int> q;
        
        for(int i = 0 ; i<V ; i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        
        
        vector<int> ans;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(int ele : adj[node]){
                if(in[ele] != 0){
                    in[ele]--;
                    if(in[ele] == 0) q.push(ele);
                }
            }
        }
        
        if(ans.size() < V) return true;
        
        return false;
        
    }
};