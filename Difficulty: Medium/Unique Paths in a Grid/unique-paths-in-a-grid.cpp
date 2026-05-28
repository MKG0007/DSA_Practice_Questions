class Solution {
  public:
  
  int helper(vector<vector<int>> &arr , int i , int j , int row , int col , vector<vector<int>> &dp){
      if(i<0 || j<0 || i>=row || j>=col || arr[i][j] == 1) return 0;
      
      if(i == 0 && j == 0) return 1;
      
      if(dp[i][j] != -1) return dp[i][j];
      int up = helper(arr , i-1 , j , row , col , dp);
      
      int left = helper(arr , i , j-1 , row , col , dp);
      
      return dp[i][j] = up +left;
  }
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row , vector<int>(col , -1));
        return helper(grid , row-1 , col-1 , row , col , dp);
    }
};