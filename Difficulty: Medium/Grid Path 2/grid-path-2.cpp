class Solution {
  public:
  int mod = 1e9+7;
  int helper(vector<vector<int>> &arr , vector<vector<int>> &dp , int rows , int cols , int i , int j){
      if(i<0 || j<0 || arr[i][j] == 1) return 0;
      if(i == 0 && j == 0) return 1;
      if(dp[i][j] != -1) return dp[i][j];
      int up = helper(arr , dp , rows , cols , i-1 , j);
      int left = helper(arr , dp , rows , cols , i , j-1);
      
      return dp[i][j] = (up + left)%mod;
      
  }
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows , vector<int>(cols , -1));
        
        return helper(grid , dp , rows , cols , rows-1 , cols-1);
        
    }
};