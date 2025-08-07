class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int row = adj.size();
        int col = adj[0].size();
        
        vector<int> vis(row , 0);
        vector<int> ans;
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int ele : adj[node]){
                if(!vis[ele]){
                    q.push(ele);
                    vis[ele] = 1;
                }
            }
        }
        
        
        return ans;
    }
};