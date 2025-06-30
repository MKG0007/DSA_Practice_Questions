class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();
        if(row == 1 && col == 1){
            return 0;
        }


        int totalFreshOrange = 0;
        vector<vector<int>> vis(row , vector<int>(col , 0));
        queue<pair<int , int>> q;
        vector<pair<int , int>> dec = {{0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1}};

        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ; j<col ; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 1;
                    q.push({i , j});
                }
                else if(grid[i][j] == 1){
                    totalFreshOrange++;
                }
            }
        }

        if(totalFreshOrange == 0) return 0;

        int min = -1;
        while(!q.empty()){
            int size = q.size();
            min++;
            for(int i = 0 ; i<size ; i++){
                auto node = q.front();
                q.pop();
                for(auto d : dec){
                    int di = d.first + node.first;
                    int dj = d.second + node.second;

                    if(di>=0 && dj>=0 && di<row && dj<col && !vis[di][dj] && grid[di][dj] == 1){
                        vis[di][dj] = 1;
                        grid[di][dj] = 2;
                        q.push({di , dj});
                        totalFreshOrange--;
                    }
                }

            }
        }

        if(totalFreshOrange>0){
            return -1;
        }
        return min;

        
    }
};