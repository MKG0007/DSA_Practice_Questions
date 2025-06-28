// User function Template for C++

class Solution {
  public:
  void fnDfs(vector<vector<int>>& grid , vector<vector<int>>& vis , vector<pair<int , int>> d , vector<pair<int , int>> &ans , int i , int j , int bi , int bj ){
      
      vis[i][j] = 1;
      ans.push_back({i-bi , j-bj});
      
      
      for(auto dd : d){
          int di = dd.first + i;
          int dj = dd.second + j;
          
          if(di>=0 && dj>=0 && di<grid.size() && dj<grid[0].size() && !vis[di][dj] && grid[di][dj] == 1){
              fnDfs(grid , vis , d , ans , di , dj , bi , bj);
          }
      }
      
      
      
  }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> vis(row , vector<int>(col , 0));
        vector<pair<int , int>> d = {{0 , 1} , {-1 , 0} ,{1 , 0} , {0 , -1}};
        set<vector<pair<int , int>>> s;
        
        
        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ; j<col ; j++){
                    vector<pair<int , int>> ans;
                    if(!vis[i][j] && grid[i][j] == 1){
                        fnDfs(grid , vis , d , ans , i , j , i , j);
                        s.insert(ans);
                    }
            }
        }
        return s.size();
        
    }
};
