class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &arr) {
        // code here
        int row = arr.size();
        int col = arr[0].size();
        vector<pair<int , int>> mark;
        
        for(int i = 0 ; i<row ; i++){
            
            for(int j = 0 ; j<col ; j++){
                if(arr[i][j] == 0) {
                    mark.push_back({i , j});
                    
                }
            }
        }
        
        for(auto ele : mark){
            int i = ele.first;
            int j = ele.second;
            
            for(int m = 0 ; m<row ; m++){
                if(arr[m][j] != 0){
                    arr[m][j] = 0;
                }
            }
            
            for(int n = 0 ; n<col ; n++){
                if(arr[i][n] != 0){
                    arr[i][n] = 0;
                }
            }
        }
        
    }
};