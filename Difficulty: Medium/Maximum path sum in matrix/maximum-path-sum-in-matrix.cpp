// User function Template for C++

class Solution {
  public:

    int maximumPath(vector<vector<int>>& arr) {
        int rows = arr.size();
        int cols = arr[0].size();
        
        vector<int> dp(cols , 0);
        for(int i = 0 ; i<cols ; i++) dp[i] = arr[0][i];
        
        for(int i  = 1 ; i<rows ; i++){
            vector<int> crr (cols , 0);
            for(int j = 0 ; j<cols ; j++){
                int up = arr[i][j] + dp[j];
                int ld = arr[i][j];
                int rd = arr[i][j];
                (j>0)? ld += dp[j-1] : ld += INT_MIN;
                (j<cols-1)? rd+= dp[j+1] : rd += INT_MIN;
                
                crr[j] = max(up , max(rd , ld));
            }
            dp = crr;
        }
        
        int maxi = INT_MIN;
        for(int i = 0 ; i<cols ; i++){
            maxi = max(maxi , dp[i]);
        }
        return maxi;
        
    }
};