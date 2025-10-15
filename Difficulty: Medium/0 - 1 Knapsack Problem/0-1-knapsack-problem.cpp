class Solution {
  public:
  
  int maxsum(vector<int> &val , vector<int> &wt , vector<vector<int>> &dp , int index , int limit){
      if(limit == 0) return 0;
      if(limit <0 || index <0) return 0;
      
      if(dp[index][limit] != -1) return dp[index][limit];
      int take = INT_MIN;
      if(wt[index]<=limit) take = val[index] +
      maxsum(val , wt , dp , index-1 , limit-wt[index]);
      
      int nottake = maxsum(val , wt , dp , index-1 , limit);
      
      return dp[index][limit] = max(take , nottake);
      
  }
    int knapsack(int w, vector<int> &val, vector<int> &wt) {
        // code here
        int size = val.size();
        vector<vector<int>> dp(size , vector<int>(w+1 , -1));
        
        return maxsum(val , wt , dp , size-1 , w);
    }
};