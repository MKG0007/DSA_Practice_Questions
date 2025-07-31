class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<vector<int>> ans(n , vector<int>(n , 0));
        
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                ans[i][j] = mat[j][n-1-i] ;
            }
        }
        
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                mat[i][j] = ans[i][j];
            }
        }
        
        
    }
};
