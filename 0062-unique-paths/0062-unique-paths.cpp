class Solution {
public:

    int helper(int m , int n , int i , int j , vector<vector<int>> &dp){
        if(j<0 || i<0) return 0;
        if(i == 0 && j == 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int left = helper(m , n , i , j-1 , dp);
        int up = helper(m , n, i-1 , j , dp);

        return dp[i][j] = left+up; 
    }
    int uniquePaths(int m, int n) {
        if(m<0 || n<0) return 0;
        if(m == 0 && n == 0) return 1;
        vector<vector<int>> dp(m , vector<int>(n , -1));
        return helper(m , n , m-1 , n-1 , dp); 
    }
};