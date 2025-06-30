class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int row = adj.size();
        
        vector<int> dis(row , 1e9);
        
        queue<pair<int , int>> q;
        
        dis[src] = 0;
        
        q.push({src , 0});
        
        while(!q.empty()){
            int node = q.front().first;
            int w = q.front().second;
            q.pop();
            
            for(auto ele : adj[node]){
                if(dis[node] + 1 <dis[ele]){
                    dis[ele] = dis[node]+1;
                    q.push({ele , dis[ele]});

                }
            }
        }
        
        
        vector<int> ans (row , -1);
        
        for(int i = 0 ; i<row ; i++){
            if(dis[i] != 1e9){
                ans[i] = dis[i];
            }
        }
        
        
        return ans;
        
        
        
        
    }
};