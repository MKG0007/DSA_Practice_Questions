class Solution {
  public:
  
    bool check(vector<int> &arr , int sum , int index , vector<vector<int>> &dp){
        if(sum == 0) return true;
        if(index == 0) return arr[index] == sum;
        
        if(dp[index][sum] != -1) return dp[index][sum];
        
        bool notpick = check(arr , sum , index-1 , dp);
        
        bool pick = false;
        
        if(arr[index]<=sum) pick = check(arr , sum-arr[index] , index-1 , dp);
        
        return dp[index][sum] = notpick || pick;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int size = arr.size();
        vector<vector<int>> dp(size , vector<int>(sum+1 , -1));
        
        return check(arr , sum , size-1 , dp);
        
        
        
    }
};