class Solution {
  public:
  
  int helper(vector<int> &arr , int index , vector<int> &dp){
      if(index < 0) return 0;
      if(index == 0) return arr[index];
      
      if(dp[index] != -1) return dp[index];
      int pick = arr[index] + helper(arr , index-2 , dp);
      
      int npick = helper(arr , index-1 , dp);
      
      
      return dp[index] = max(pick , npick);
      
      
  }
    int findMaxSum(vector<int>& arr) {
        // code here
        int size = arr.size();
        vector<int> dp(size , -1);
        return helper(arr , size-1 , dp);
        
    }
};