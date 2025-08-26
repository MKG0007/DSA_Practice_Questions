class Solution {
  public:
  
  int minPath(vector<int> &height , vector<int> &dp , int num){
      if(num == 0){
          return 0;
      }
      if(dp[num] != -1) return dp[num];
      int left = minPath(height , dp , num-1) +abs(height[num] - height[num-1]);
      int right = INT_MAX;
      if(num > 1) {right = minPath(height , dp , num-2) +abs(height[num]- height[num-2]);}
      dp[num] = min(left , right);
      return dp[num];
  }
  
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n+1 , -1);
        
        return minPath(height , dp , n-1);
        
    }
};