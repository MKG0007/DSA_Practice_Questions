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
        
        
        vector<vector<int>> dp(row , vector<int>(col+1 , -1));
        
        dp[0][0] = max(arr[0][1] , arr[0][2]);
        dp[0][2] = max(arr[0][1] , arr[0][0]);
        dp[0][1] = max(arr[0][2] , arr[0][0]);
        dp[0][3] = max({arr[0][0] , arr[0][1] , arr[0][2]});
        
        
        for(int day = 1 ; day<row ; day++){
            
            for(int last = 0 ; last<4 ; last++){
                dp[day][last] = 0;
                for(int task = 0 ; task<3 ; task++){
                    if(last == task) continue;
                    int path = arr[day][task]+dp[day-1][task];
                    
                    dp[day][last] = max(dp[day][last] , path);
                }
            }
        }
        
        return dp[row-1][3];
        
    }
};