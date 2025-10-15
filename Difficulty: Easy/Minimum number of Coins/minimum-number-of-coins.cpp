class Solution {
  public:
  int totalWays(vector<int> &arr , int t , vector<vector<int>> &dp ,int index){
    if(t == 0) return 0;
    if(index == 0){
        if(t%arr[0] == 0) return t/arr[0];
        return 1e6;
    }
    if(dp[index][t] != -1) return dp[index][t];
    int nottake = totalWays(arr , t , dp , index -1);

    int take = 1e6;
    if(arr[index]<=t) take = 1+ totalWays(arr , t-arr[index] , dp , index);

    return dp[index][t] =  min(take , nottake);
}
    int findMin(int n) {
        // code here
        vector<int> arr = {1 , 2 , 5, 10};
        
        int size = arr.size();
        vector<vector<int>> dp(size , vector<int>(n+1 , -1));
        
        
        int r = totalWays(arr , n , dp , size-1);
        
        if(r == 1e6) return -1;
        
        return r;
    }
};