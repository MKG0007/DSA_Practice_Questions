class Solution {
  public:
  
  int count(int num , vector<int> &dp){
      if(num == 0){
          return 1;
      }
      else if(num == 1){
          return 1;
      }
      
      if(dp[num] != -1){
          return dp[num];
      }
      
      dp[num] = count(num-1 , dp) + count(num-2 , dp);
      return dp[num];
  }
    int countWays(int n) {
        vector<int> dp(n+1 , -1);
        
        return count(n , dp);
        
    }
};
