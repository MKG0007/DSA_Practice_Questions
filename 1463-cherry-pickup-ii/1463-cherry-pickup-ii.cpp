class Solution {
public:
int helper(vector<vector<int>> &arr , vector<vector<vector<int>>> &dp , int i , int j1 , int j2){
    if(j1<0 || j2<0 || i>=arr.size() || j1>=arr[0].size() || j2>=arr[0].size()) return INT_MIN;
    if(i == arr.size()-1){
        if(j1 == j2) return arr[i][j1];
        else return arr[i][j1]+arr[i][j2];
    }
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    int maxi = INT_MIN;
    for(int jj1 = -1 ; jj1<=1 ; jj1++){
        for(int jj2 = -1 ; jj2<=1 ; jj2++){
            int sum = arr[i][j1];
            if(j1 != j2) sum += arr[i][j2];
            sum += helper(arr , dp , i+1 , j1+jj1 , j2+jj2);
            maxi = max(maxi , sum);
        }
    }

    return dp[i][j1][j2] = maxi;
}
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<vector<int>>> dp(rows , vector<vector<int>>(cols , vector<int>(cols , -1)));
        return helper(grid ,dp ,0 , 0 , cols-1);
        
    }
};