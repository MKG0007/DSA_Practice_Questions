class Solution {
  public:
  
  int findMax(vector<vector<int>> &dp , vector<vector<int>> &arr , int index , int prev){
      if(index == 0){
          int maxChoice = INT_MIN;
          for(int i = 0 ; i<3 ; i++){
              if(i == prev) continue;
              
              maxChoice = max(maxChoice , arr[0][i]);
          }
          return maxChoice;
      }
      
      if(dp[index][prev] != -1) return dp[index][prev];
      int maxChoice = INT_MIN;
      
      for(int i = 0 ; i<3 ; i++){
          if(prev == i) continue;
          
          int path = arr[index][i] + findMax(dp , arr , index-1 , i);
          maxChoice = max(maxChoice , path);
          
      }
      
      return dp[index][prev] = maxChoice;
  }
    int maximumPoints(vector<vector<int>>& arr) {
        int row = arr.size();
        int col = arr[0].size();
        
        vector<vector<int>> dp(row+1 , vector<int>(col+1 , -1));
        
        return findMax(dp , arr , row-1 , 3);
        
    }
};