class Solution {
public:
int maxsum(vector<vector<int>>& grid , vector<vector<int>>& dp , int row , int col){
    if(row == 0 && col == 0) return grid[row][col];
    if(row<0 || col <0) return 1e6;
    if(dp[row][col] != -1) return dp[row][col];
    int left = grid[row][col] + maxsum(grid , dp , row , col-1);
    int right = grid[row][col] + maxsum(grid , dp , row-1 , col);

    return dp[row][col] = min(left , right);




}
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> dp(row , vector<int>(col , -1));

        return maxsum(grid , dp , row-1 , col-1);
    }
};