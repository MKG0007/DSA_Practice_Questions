class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> dp(row , vector<int>(col , 0));
        dp[0][0] = grid[0][0];
        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ; j<col ; j++){
                if(i != 0 || j != 0){
                    int left = 1e5;
                    int up = 1e5;
                    if(i>0) up = grid[i][j] + dp[i-1][j];
                    if(j>0) left = grid[i][j] + dp[i][j-1];
                    dp[i][j] = min(up , left); 
                }
            }
        }

        return dp[row-1][col-1];
    }
};