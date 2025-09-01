class Solution {
  public:
  
  
  int maxPoints(vector<vector<int>> &dp , vector<vector<int>> &arr , int index , int prev){
      if(index == 0){
          int maxi = INT_MIN;
          for(int i = 0 ; i<3 ; i++){
              if(i == prev) continue;
              maxi = max(maxi , arr[index][i]);
          }
          
          return maxi;
      }
      
      if(dp[index][prev] != -1) return dp[index][prev];
      
      int maxi = INT_MIN;
      
      for(int i = 0 ; i<3 ; i++){
          if(prev == i) continue;
          
          int points = arr[index][i]+maxPoints(dp , arr , index-1 , i);
          
          maxi = max(maxi , points);
      }
      
      return dp[index][prev] =  maxi;
      
      
  }
    int maximumPoints(vector<vector<int>>& arr) {
        int row = arr.size();
        int col = arr[0].size();
        
        vector<vector<int>> dp(row , vector<int>(col+1 , -1));
        
        return maxPoints(dp , arr , row-1 , 3);
        
    }
};