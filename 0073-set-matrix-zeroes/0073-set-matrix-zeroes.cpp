class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int row = arr.size();
        int col = arr[0].size();
        int ccol = 1;
        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ; j<col ; j++){
                if(arr[i][j] == 0){
                    arr[i][0] = 0;

                    if(j>0) arr[0][j] = 0;
                    else ccol = 0;
                }
            }
        }

        for(int i = 1 ; i<row ; i++){
            for(int j = 1 ; j<col ; j++){
                if(arr[0][j] == 0 || arr[i][0] == 0) arr[i][j] = 0;

            }
        }

        if(arr[0][0] == 0){
            for(int i = 0 ; i<row ; i++){
                arr[i][0] = 0;
            }
        }

        if(ccol == 0){
            for(int i = 0 ; i<col ; i++){
                arr[0][i] = 0;
            }
        }
        
        
    }
};