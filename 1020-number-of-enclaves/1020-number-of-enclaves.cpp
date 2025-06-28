class Solution {
public:

    void fnDfs(vector<vector<int>>& grid , vector<vector<int>>& vis , vector<pair<int , int>>& dec , int i , int j){
        vis[i][j] = 1;

        for(auto d : dec){
            int di = d.first + i;
            int dj = d.second + j;

            if(di>=0 && dj>=0 && dj<grid[0].size() && di<grid.size() && !vis[di][dj] && grid[di][dj] == 1){
                fnDfs(grid , vis , dec , di , dj);
            }
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();


        vector<vector<int>> vis(row , vector<int>(col , 0));
        vector<pair<int , int>> dec = {{0 , 1} , {0 , -1} , {1 , 0} , {-1 , 0}};
        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ; j<col ; j++){
                if(i == 0 || j == 0 || j == col-1 || i == row-1){
                    if(!vis[i][j] && grid[i][j] == 1){
                        fnDfs(grid , vis , dec , i , j);
                    }
                }
           
            }
        }
        int count = 0;
        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ; j<col ; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    count++;

                }
            }
        }
        return count;
    }
};