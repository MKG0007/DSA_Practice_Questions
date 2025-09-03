class Solution {
public:


    int maxCount(vector<vector<int>> &grid , vector<vector<vector<int>>> & dp , int i , int j1 , int j2 , int row , int col){
        if(j1<0 || j2<0 || j2>=col || j1>=col) return -1e7;

        if(i == row-1){
            int val = grid[i][j1];
            if(j1 == j2) return val;

            return val+grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxi = 0;

        for(int dj1 = -1 ; dj1<=1 ; dj1++){
            for(int dj2 = -1 ; dj2<=1 ; dj2++){
                int val = 0;
                if(j1 == j2) val = grid[i][j1];
                else val = grid[i][j1]+grid[i][j2];

                val += maxCount(grid , dp , i+1 , j1+dj1 , j2+dj2 , row , col);
            maxi = max(maxi , val);
            }
        }

        return dp[i][j1][j2] = maxi;
    }
int cherryPickup(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();

    // dp[i][j1][j2] = max cherries from row i when robot1 at col j1 and robot2 at col j2
    vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, -1)));

    // base case → last row
    for (int j1 = 0; j1 < col; j1++) {
        for (int j2 = 0; j2 < col; j2++) {
            if (j1 == j2) dp[row-1][j1][j2] = grid[row-1][j1];
            else dp[row-1][j1][j2] = grid[row-1][j1] + grid[row-1][j2];
        }
    }

    // bottom-up fill
    for (int i = row-2; i >= 0; i--) {
        for (int j1 = 0; j1 < col; j1++) {
            for (int j2 = 0; j2 < col; j2++) {
                int maxi = INT_MIN;
                for (int dj1 = -1; dj1 <= 1; dj1++) {
                    for (int dj2 = -1; dj2 <= 1; dj2++) {
                        int val = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];

                        if (j1+dj1 >= 0 && j1+dj1 < col && j2+dj2 >= 0 && j2+dj2 < col) {
                            val += dp[i+1][j1+dj1][j2+dj2];
                        } else {
                            val = INT_MIN;
                        }
                        maxi = max(maxi, val);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][col-1];  // start positions: robot1 at (0,0), robot2 at (0,col-1)
}
};