// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    
    int findSum(vector<int> &dp , vector<int> &arr , int index){
        if(index == 0) return arr[index];
        if(index <0) return 0;
        if(dp[index] != -1) return dp[index];
        // pick the element 
        int pick = arr[index] + findSum(dp , arr , index-2);
        
        int notpick = 0+ findSum(dp , arr , index-1);
        
        
        return dp[index] = max (pick , notpick);
        
        //not pick the element
    }
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> dp(n+1 , -1);
        
        return findSum(dp , arr , n-1);
        
    }
};