class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        
        int count = -1;
        for(int i = 0 ; i<n ; i++){
            int check1 = 1;
            int check2 = 1;
            for(int j = 0 ; j<n ; j++){
                if(j != i && mat[j][i] != 1){
                    check1 = 0;
                    break;
                }
            }
    
            for(int k = 0 ; k<n ; k++){
                    if(i != k && mat[i][k] != 0){
                        check2 = 0;
                        break;
                    }
            }
            
            if(check1 && check2) return i;
        }
        
        return -1;
    }
};