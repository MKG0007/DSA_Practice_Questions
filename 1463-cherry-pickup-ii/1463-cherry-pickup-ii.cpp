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

        vector<vector<vector<int>>> dp(row , vector<vector<int>>(col , vector<int>(col , -1)));
        return maxCount(grid , dp , 0 , 0 , col-1 , row , col);
        
    }
};