class Solution {
  public:
    int maxPickup(int i , int j1 , int j2 , int row  , int col , vector<vector<int>>& grid , vector<vector<vector<int>>> &dp){
        if(i>=row || j1<0 || j1>=col || j2<0 || j2>=col){
            return -1e8;
        }

        if(i == row-1) {
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];

        }
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        // explore all the path
        int maxi = INT_MIN;
        for(int dj1 = -1 ; dj1<=1 ; dj1++){
            for(int dj2 = -1 ; dj2<=1 ; dj2++){
                int value = 0;
                if(j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];

                value += maxPickup(i+1 , j1+dj1 , j2+dj2 , row , col , grid , dp);
                maxi = max(maxi , value);

            }
        }

        return dp[i][j1][j2] = maxi;


    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        int row = n;
        int col = m;

        vector<vector<vector<int>>> dp(row , vector<vector<int>>(col , vector<int>(col , -1)));

        return maxPickup(0 , 0 , col-1 , row , col , grid , dp);
        
    }
};