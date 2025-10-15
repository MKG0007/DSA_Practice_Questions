class Solution {
  public:
  
  int count(vector<int> &arr , vector<vector<int>> &dp , int t , int index){
      if(index == 0){
          if(t == 0 && arr[0] == 0) return 2;
          if(t == 0 || arr[0] == t) return 1;
          return 0;
      }
      
      if(dp[index][t] != -1) return dp[index][t];
      
      int take = 0;
      if(arr[index] <= t) 
          take = count(arr , dp , t - arr[index] , index - 1);
      
      int nottake = count(arr , dp , t , index - 1);
      
      return dp[index][t] = take + nottake;
  }
  
  int countPartitions(vector<int>& arr, int d) {
      int size = arr.size();
      int total = 0;
      for(int i = 0; i < size; i++) total += arr[i];
      
      int t = total - d;
      if(t < 0 || t % 2 != 0) return 0; 
      
      t /= 2;
      vector<vector<int>> dp(size, vector<int>(t + 1, -1));
      
      return count(arr, dp, t, size - 1);
  }
};
