class Solution {
  public:
    int helper(int i,int j,vector<vector<int>>& mat,int target,vector<vector<vector<int>>>& dp){
        if(i==0 && j==0){
            if(target==mat[i][j]) return 1;
            else return 0;
        }
        if(i<0 || j<0 || target<0) return 0;
        
        if(dp[i][j][target]!=-1) return dp[i][j][target];
        
        int left=helper(i,j-1,mat,target-mat[i][j],dp);
        
        int up=helper(i-1,j,mat,target-mat[i][j],dp);
        
        return dp[i][j][target]=up+left;
    }
    int numberOfPath(vector<vector<int>>& mat, int k) {
        
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        
        return helper(n-1,m-1,mat,k,dp);
    }
};