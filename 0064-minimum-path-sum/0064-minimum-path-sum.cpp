class Solution {
public:

    int path(vector<vector<int>> &dp , vector<vector<int>> &arr , int i , int j , int row , int col){
        if(i<0 || i>row || j<0 || j>col) return 1e7;

        if(i == 0 && j == 0) return arr[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int p1 = arr[i][j] + path(dp , arr , i-1 , j , row , col);
        int p2 = arr[i][j] + path(dp , arr , i , j-1 , row , col);

        return dp[i][j] = min(p1 , p2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row+1 , vector<int>(col+1 , -1));

        return path(dp , grid , row-1 , col-1 , row , col);

        
    }
};