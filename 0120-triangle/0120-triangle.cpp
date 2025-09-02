class Solution {
public:
    int minimumTotal(vector<vector<int>>& arr) {
        int row = arr.size();
        
        vector<vector<int>> dp(row , vector<int>(row , -1));
        
        for(int j = 0 ; j<row ; j++) dp[row-1][j] = arr[row-1][j];
        
        for(int i = row-2 ; i>=0 ; i--){
            for(int j = i ; j>=0 ; j--){
                int p1 = arr[i][j] + dp[i+1][j];
                int p2 = arr[i][j] + dp[i+1][j+1];
                
                dp[i][j] = min(p1 , p2);
            }
        }
        
        return dp[0][0];
    }
};