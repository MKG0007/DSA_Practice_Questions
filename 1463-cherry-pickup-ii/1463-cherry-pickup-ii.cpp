class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<vector<int>>> dp(
            rows, vector<vector<int>>(cols, vector<int>(cols, 0)));
        for (int j1 = 0; j1 < cols; j1++) {
            for (int j2 = 0; j2 < cols; j2++) {
                dp[rows - 1][j1][j2] = grid[rows - 1][j1];
                if (j1 != j2)
                    dp[rows - 1][j1][j2] += grid[rows - 1][j2];
            }
        }

        for (int i = rows - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < cols; j1++) {
                for (int j2 = 0; j2 < cols; j2++) {
                    int maxi = INT_MIN;
                    for (int jj1 = -1; jj1 <= 1; jj1++) {
                        for (int jj2 = -1; jj2 <= 1; jj2++) {
                            int sum = grid[i][j1];
                            if (j1 != j2)
                                sum += grid[i][j2];
                            if(j1+jj1>=0 && j1+jj1<cols && j2+jj2>=0 && j2+jj2<cols){
                                sum += dp[i+1][j1+jj1][j2+jj2];
                            }
                            else sum += INT_MIN;
                            maxi = max(maxi, sum);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
return dp[0][0][cols-1];
    }
};