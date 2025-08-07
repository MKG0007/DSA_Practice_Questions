// User function Template for C++

class Solution {
  public:
    void dfs(unordered_map<int , vector<int>> &adj , vector<int> &vis , int node){
        vis[node]  = 1;
        
        for(int ele : adj[node]){
            if(!vis[ele]){
                dfs(adj , vis , ele);
            }
        }
        
    }
    int numProvinces(vector<vector<int>> mat, int V) {
        int row = mat.size();
        int col = mat[0].size();
        unordered_map<int , vector<int>> adj;
        vector<int> vis(V , 0);
        
        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ; j<col ; j++){
                if(mat[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int count = 0;
        for(int i = 0 ; i<V ; i++){
            if(!vis[i]){
                dfs(adj , vis , i);
                count++;
            }
        }
        
        return count;
    }
};