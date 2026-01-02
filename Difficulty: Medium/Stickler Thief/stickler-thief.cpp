class Solution {
  public:
  
  int helper(vector<int> &arr , vector<int> &dp , int index){
      if(index == 0) return arr[0];
      if(index<0) return 0;
      if(dp[index] != -1 ) return dp[index];
      int take = arr[index] + helper(arr , dp , index-2);
      int ntake = helper(arr , dp , index-1);
      
      return dp[index] = max(take , ntake);
  }
    int findMaxSum(vector<int>& arr) {
        // code here
        int size = arr.size();
        vector<int> dp(size , -1);
        return helper(arr , dp , size-1);
    }
};