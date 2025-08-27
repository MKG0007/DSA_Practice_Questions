class Solution {
  public:
  
  
    int cost(vector<int> &dp , vector<int> &arr , int index){
        if(index == 0) return 0;
        if(dp[index] != -1) return dp[index];
        
        int left = cost(dp , arr ,index-1) + abs(arr[index] - arr[index-1]);
        int right = INT_MAX;
        if(index>1) right = cost(dp , arr , index-2) + abs(arr[index]-arr[index-2]);
        
        return dp[index] = min(left , right);
    }
    int minCost(vector<int>& height) {
        int n = height.size();
        
        vector<int> dp(n+1 , -1);
        
        int result = cost(dp , height , n-1);
        
        return result;
        
    }
};