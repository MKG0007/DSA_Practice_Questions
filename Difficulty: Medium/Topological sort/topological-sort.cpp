class Solution {
  public:
    void topo(unordered_map<int , vector<int>> adj , vector<int> &vis , queue<int> &q , int node){
        
        
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        int v = V;
        unordered_map<int , vector<int>> adj;
        queue<int> q;
        vector<int> inDegree(v , 0);
        
        
        
        
        for(auto edge : edges){
            int u = edge[0];
            int vv = edge[1];
            adj[u].push_back(vv);
            inDegree[vv]++;
        }
        
        for(int i = 0 ; i<v ; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(int i : adj[node]){
                inDegree[i]--;
                
                if(inDegree[i] == 0){
                    q.push(i);
                }
            }
        }
        
        return ans;
    }
};