class Solution {
  public:
    
    int count(vector<int> &arr , vector<vector<int>> &dp , int index , int t){
        if (index == 0) {
            if (t == 0 && arr[0] == 0) return 2; // {} and {0}
            if (t == 0) return 1;               // only {}
            return (arr[0] == t) ? 1 : 0;
        }
        if(dp[index][t] != -1) return dp[index][t];
        
        int notpick = count(arr , dp , index-1 , t);
        int pick = 0;
        if(arr[index]<=t) pick = count(arr , dp , index-1 , t-arr[index]);
        
        return dp[index][t] = notpick+pick;
    }
    int perfectSum(vector<int>& arr, int target) {
        int size = arr.size();
        vector<vector<int>> dp(size+1 , vector<int> (target+1 , -1));
        
        return count(arr , dp , size-1 , target);
        
    }
};