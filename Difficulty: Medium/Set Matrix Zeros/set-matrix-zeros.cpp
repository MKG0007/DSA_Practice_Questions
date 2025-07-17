class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &matrix) {
        // code here
        stack<pair<int , int>> st;
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ; j<col ; j++){
                if(matrix[i][j] == 0){
                    st.push({i , j});
                }
            }
        }

        while(!st.empty()){
            int i = st.top().first;
            int j = st.top().second;
            int tempi = 0;
            int tempj = 0;
            st.pop();

            while(tempj != col){
                matrix[i][tempj] = 0;
                tempj++;
            }

            while(tempi != row){
                matrix[tempi][j] = 0;
                tempi++;
            }
        }
    }
};