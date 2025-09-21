// User function template for C++
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int row = mat.size();
        int col = mat[0].size();
        
        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ;j<col ; j++){
                if(mat[i][0]<= x && x<=mat[i][col-1]){
                    if(mat[i][j] == x) return true;
                }
                else{
                    break;
                }
            }
        }
        
        
        return false;
    }
};