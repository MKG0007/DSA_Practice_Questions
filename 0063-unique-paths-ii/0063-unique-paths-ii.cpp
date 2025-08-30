class Solution {
public:
  
    int path(vector<vector<int>> &dp, vector<vector<int>>& arr , int m , int n){
        if(m<0 || n<0 || arr[m][n] == 1) return 0;

        if(m == 0 && n == 0){
            return 1;
        }
        
        if(dp[m][n] != -1) return dp[m][n];
        
        int up = path(dp , arr , m-1 , n);
        
        int left = path(dp, arr , m , n-1);
        
        return dp[m][n] = up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {

        int m = arr.size();
        int n = arr[0].size();

         vector<vector<int>> dp(m+1 , vector<int>(n+1 , -1));
        return path( dp, arr , m-1 , n-1);
        
    }
};