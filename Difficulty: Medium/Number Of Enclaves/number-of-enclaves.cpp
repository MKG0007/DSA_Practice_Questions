// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> vis(row , vector<int>(col , 0));
        vector<pair<int , int>> dec = {{0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1}};
        queue<pair<int , int>> q;
        int count = 0;
        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ; j<col ; j++){
                if(i == 0 || j == 0 || j == col-1 || i == row-1){
                    if(grid[i][j] == 1){
                        q.push({i , j});
                        vis[i][j] = 1;
                    }
                }
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        count = count - q.size();
        while(!q.empty()){
            auto n = q.front();
            q.pop();
            
            for(auto d : dec){
                int di = d.first + n.first;
                int dj = d.second + n.second;
                
                if(di>=0 && dj>=0 && di<row && dj<col && !vis[di][dj] && grid[di][dj] == 1){
                    vis[di][dj] = 1;
                    q.push({di , dj});
                    count--;
                }
            }
            
            
        }
        return count;
        
    }
};
