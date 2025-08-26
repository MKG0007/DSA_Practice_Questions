// User function Template for C++
class Solution {
  public:
  int fibo(int num , vector<int> &dp){
      if(num <=1) return num;
      
      if(dp[num] != -1){
          return dp[num];
      }
      dp[num] = fibo(num-1 , dp)+fibo(num-2 , dp);
      return dp[num];
      
  }
    int nthFibonacci(int n) {
        vector<int> dp(n+1 , -1);
        
        return fibo(n , dp);
        
    }
};