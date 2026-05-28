class Solution {
public:
int helper(vector<vector<int>> &arr , int i , int j , int row , int col , vector<vector<int>> &dp){
    if(i <0 || j<0 || i>=row || j>=col) return 1e8;
    if(i == 0 && j == 0) return arr[i][j];
    if(dp[i][j] != -1) return dp[i][j];
    int up = arr[i][j] + helper(arr , i-1 , j , row , col , dp);

    int left = arr[i][j] + helper(arr , i , j-1 , row , col , dp);

    return dp[i][j] = min(up , left);
}
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row , vector<int>(col , -1));
        return helper(grid , row-1 , col-1 , row , col , dp);
    }
};