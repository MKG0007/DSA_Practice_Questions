class Solution {
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        int rows = grid.size();
        int cols = grid[0].size();
                if (grid[0][0] == 1) return 0;
        vector<vector<int>> dp(rows , vector<int>(cols , 0));
        for(int i = 0 ; i<rows ; i++){
            for(int j = 0 ; j<cols ; j++){
                if(i == 0 && j == 0) dp[0][0] = 1;
                else if(grid[i][j] == 0){
                    int num  = 0;
                    if(i>0) num += dp[i-1][j];
                    if(j>0) num += dp[i][j-1];
                    dp[i][j] = num;
                }
            }
        }
        
        return dp[rows-1][cols-1];
        
    }
};