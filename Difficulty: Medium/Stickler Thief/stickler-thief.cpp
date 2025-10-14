class Solution {
  public:
  
  int maxsum(vector<int> &dp , vector<int> &arr , int index){
      if(index < 0) return 0;
      if(index == 0) return arr[0];
      
      if(dp[index] != -1) return dp[index];
      int pick = arr[index] + maxsum(dp , arr , index-2);
      int notpick = 0 + maxsum(dp , arr , index-1);
      
      return dp[index] = max(pick , notpick);
      
  }
    int findMaxSum(vector<int>& arr) {
        
        
        int size = arr.size();
        
        vector<int> dp(size , -1);
        
        return maxsum(dp , arr , size-1);
        
        
        
    }
};