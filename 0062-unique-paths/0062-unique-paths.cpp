class Solution {
public:
    int path(vector<vector<int>> &dp , int m , int n , int row  , int col){
        if(m<0 || m>row || n<0 || n>col) return 0;

        if(m == 0 && n == 0) return 1;
        if(dp[m][n] != -1) return dp[m][n];
        int p1 = path(dp , m-1 , n , row , col);
        int p2 = path(dp , m , n-1 , row , col);

        return dp[m][n] = p1+p2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1 , vector<int>(n+1 , -1));

        return path(dp , m-1 , n-1 , m , n);
        
    }
};