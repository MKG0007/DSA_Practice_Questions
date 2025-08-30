class Solution {
public:
  
    int path(vector<vector<int>> &dp ,vector<vector<int>>& arr , int m , int n){
        if(m<0 || n<0) return INT_MAX;

        if(dp[m][n] != -1) return dp[m][n];

        if(m == 0 && n == 0){
            return arr[m][n];
        }
        
        int up = path(dp , arr, m-1 , n);
        int left = path(dp , arr, m , n-1);

        int res = INT_MAX;
        if(left != INT_MAX) res = min(res,arr[m][n] + left);
        if(up != INT_MAX) res = min(res, arr[m][n] + up);
        
        return dp[m][n] = res;
    }
    int minPathSum(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<int>> dp(m , vector<int>(n , -1));
        return path( dp ,arr ,m-1 , n-1);

    }
};