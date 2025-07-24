class Solution {
  public:
    // Function to return Breadth First Traversal of given graph
    void bfs(vector<vector<int>> &adjj , vector<int> &vis , vector<int> &ans , int node){
            vis[node] = 1;
            queue<int> q;
            q.push(node);
            
            while(!q.empty()){
                int n = q.front();
                ans.push_back(n);
                q.pop();
                for(int i : adjj[n]){
                    if(!vis[i]){
                        vis[i] = 1;
                        q.push(i);
                    }
                }
            }
    }
        
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> vis(adj.size() , 0);
        vector<int> ans;
        
        bfs(adj , vis , ans , 0);
        return ans;
        
    }
};