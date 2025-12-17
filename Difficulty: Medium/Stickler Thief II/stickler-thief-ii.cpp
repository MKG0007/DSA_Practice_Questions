class Solution {
  public:
    int helper(vector<int> &arr , vector<int> &dp , int index , int s){
        if(index < s) return 0;
        if(index == s) return arr[index];
        
        if(dp[index] != -1) return dp[index];
        int take = arr[index] + helper(arr , dp , index-2 , s);
        int ntake = helper(arr , dp , index-1 , s);
        
        return dp[index] =  max(take , ntake);
    }
    int maxValue(vector<int>& arr) {
        int size = arr.size();
        if(size == 0) return 0;
        vector<int> dp1(size , -1);
        vector<int> dp2(size , -1);
        int r1 = helper(arr , dp1 , size-1 , 1);
        int r2 = helper(arr , dp2 , size-2 , 0);
        
        return max(r1 , r2);
        
        
    }
};
