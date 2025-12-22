class Solution {
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (grid[0][0] == 1) return 0;
        vector<int> dp(cols , 0);
        for(int i = 0 ; i<rows ; i++){
            vector<int> crr(cols , 0);
            for(int j = 0 ; j<cols ; j++){
                if(i == 0 && j == 0) crr[0] = 1;
                else if(grid[i][j] == 0){
                    int num  = 0;
                    if(i>0) num += dp[j];
                    if(j>0) num += crr[j-1];
                    crr[j] = num;
                }
            }
            dp = crr;
        }
        
        return dp[cols-1];
        
    }
};