class Solution {
  public:
  
    int path(vector<vector<int>> &dp , int m , int n){
        if(m == 0 && n == 0){
            return 1;
        }
        if(m<0 || n<0) return 0;
        
        if(dp[m][n] != -1) return dp[m][n];
        
        int up = path(dp , m-1 , n);
        
        int left = path(dp , m , n-1);
        
        return dp[m][n] = up+left;
    }
    int numberOfPaths(int m, int n) {
        vector<vector<int>> dp(m+1 , vector<int>(n+1 , -1));
        return path( dp , m-1 , n-1);
        
    }
};
