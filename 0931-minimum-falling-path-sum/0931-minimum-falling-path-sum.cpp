class Solution {
public:

int path(vector<vector<int>> &dp , vector<vector<int>> &arr , int i , int j , int row , int col){
    if(j<0 || j>=col) return 1e7;
    if(i == 0) return arr[i][j];
    if(dp[i][j] != -1) return dp[i][j];
    int p1 = arr[i][j] + path(dp , arr , i-1 , j , row , col);
    int p2 = arr[i][j] + path(dp , arr , i-1 , j-1 , row , col);
    int p3 = arr[i][j] + path(dp , arr , i-1 , j+1 , row , col);

    return dp[i][j] = min({p1 , p2 , p3});


}
    int minFallingPathSum(vector<vector<int>>& arr) {
        int row = arr.size();
        int col = arr[0].size();

        vector<vector<int>> dp(row , vector<int>(col , -1));
        for(int i =0 ; i<col ; i++) dp[0][i] = arr[0][i];

        for(int i = 1 ; i<row ; i++){
            for(int j = 0 ; j<col ; j++){
                int p1 = arr[i][j] + dp[i-1][j];
                int p2 = arr[i][j];
                if(j-1<0) p2 += 1e7;
                else p2 += dp[i-1][j-1];
                int p3 = arr[i][j];
                if(j+1>=col) p3 = 1e7;
                else p3 += dp[i-1][j+1];

                dp[i][j] = min({p1 , p2 , p3});
            }
        }

        return *min_element(dp[row-1].begin() , dp[row-1].end()) ;
    }
};