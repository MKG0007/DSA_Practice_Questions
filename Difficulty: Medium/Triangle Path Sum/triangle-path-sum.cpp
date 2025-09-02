class Solution {
  public:
  
  int path(vector<vector<int>> &dp , vector<vector<int>> &arr , int i , int j , int row){
      if(i == row-1) return arr[i][j];
      
      if(dp[i][j] != -1) return dp[i][j];
      
      int p1 = arr[i][j] + path(dp , arr , i+1 , j , row);
      int p2 = arr[i][j] + path(dp , arr , i+1 , j+1 , row);
      
      return dp[i][j] = min(p1 , p2);
      
  }
    int minPathSum(vector<vector<int>>& arr) {
        int row = arr.size();
        
        vector<vector<int>> dp(row , vector<int>(row , -1));
        
        return path(dp , arr , 0 , 0 , row);
        
    }
};