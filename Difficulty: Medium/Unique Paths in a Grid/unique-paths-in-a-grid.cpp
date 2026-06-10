class Solution {
  public:
  
  int helper(vector<vector<int>> &arr , int row , int col , int i , int j , vector<vector<int>> &dp){
      if(i == 0 && j == 0 && arr[i][j] != 1) return 1;
      
      if(i<0 || j<0 || arr[i][j] == 1) return 0;
      
      if(dp[i][j] != -1) return dp[i][j];
      int left = arr[i][j] + helper(arr , row , col , i , j-1 , dp);
      
      int up = arr[i][j] + helper(arr , row , col , i-1 , j , dp);
      
      return dp[i][j] = left + up;
  }
    int uniquePaths(vector<vector<int>> &grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row , vector<int>(col , -1));
        return helper(grid , row , col , row-1 , col-1 , dp);
        
    }
};