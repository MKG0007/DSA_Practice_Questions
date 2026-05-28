class Solution {
public:
    int minPathSum(vector<vector<int>>& arr) {
        int row = arr.size();
        int col = arr[0].size();
        vector<vector<int>> dp(row , vector<int>(col , 0));
        dp[0][0] = arr[0][0];
        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ; j<col ; j++){
                if(i == 0 && j == 0) continue;

                int up = 1e8;
                int down = 1e8;

                if(i>0) up = arr[i][j] + dp[i-1][j];
                if(j>0) down = arr[i][j] + dp[i][j-1];

                dp[i][j] = min(up , down);
            }
        }

        return dp[row-1][col-1];
    }
};