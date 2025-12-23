// User function Template for C++

class Solution {
  public:

    int maximumPath(vector<vector<int>>& arr) {
        int rows = arr.size();
        int cols = arr[0].size();
        
        vector<vector<int >> dp(rows , vector<int>(cols , 0));
        for(int i = 0 ; i<cols ; i++) dp[0][i] = arr[0][i];
        
        for(int i  = 1 ; i<rows ; i++){
            for(int j = 0 ; j<cols ; j++){
                int up = arr[i][j] + dp[i-1][j];
                int ld = arr[i][j];
                int rd = arr[i][j];
                (j>0)? ld += dp[i-1][j-1] : ld += INT_MIN;
                (j<cols-1)? rd+= dp[i-1][j+1] : rd += INT_MIN;
                
                dp[i][j] = max(up , max(rd , ld));
            }
        }
        
        int maxi = INT_MIN;
        for(int i = 0 ; i<cols ; i++){
            maxi = max(maxi , dp[rows-1][i]);
        }
        return maxi;
        
    }
};