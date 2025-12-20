class Solution {
public:


int helper(int row , int col , int i , int j , vector<vector<int>> &dp){

    if(i<0 || j<0 || i>=row || j>=col) return 0;
    if(i == 0 && j == 0) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    int left = helper(row , col , i-1 , j , dp);
    int up = helper(row , col , i , j-1 , dp);

    return dp[i][j] = up + left;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector(n , -1));
        return helper(m , n , m-1 , n-1 , dp);
    }

};