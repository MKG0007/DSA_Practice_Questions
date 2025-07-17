// User function template for C++

/* matrix : given input matrix, you are require
 to change it in place without using extra space */
void rotate(vector<vector<int> >& arr) {
    int row = arr.size();
    int col = arr[0].size();
    if(row <=1 && col<=1) return;
    
    for(int i = 0 ; i<row ; i++){
        for(int j = i+1 ; j<col ; j++){
            swap(arr[i][j] , arr[j][i]);
        }
    }
    
    for(int i = 0 ; i<row ; i++){
        for(int j = 0 ; j<col/2 ; j++){
            swap(arr[i][j] , arr[i][col-j-1]);
        }
    }
    
    
}
