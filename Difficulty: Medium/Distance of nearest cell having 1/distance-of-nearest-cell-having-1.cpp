class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        
        vector<vector<int>> ans(row , vector<int>(col , 0));
        vector<vector<int>> vis(row , vector<int>(col , 0));
        vector<pair<int , int>> dec = {{0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1}};
        queue<pair<int , int>> q;
        
        
        
        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ; j<col ; j++){
                if(grid[i][j] == 1){
                    vis[i][j] = 1;
                    q.push({i , j});
                }
            }
        }
        
        while(!q.empty()){
            auto n = q.front();
            q.pop();
            
            for(auto d : dec){
                int di = n.first + d.first;
                int dj = n.second + d.second;
                
                if(dj>=0 && di>=0 && dj<col && di<row && !vis[di][dj] && grid[di][dj] == 0){
                    vis[di][dj] = 1;
                    q.push({di , dj});
                    ans[di][dj] = ans[n.first][n.second]+1;
                }
            }
        }
        
        return ans;
    }
};