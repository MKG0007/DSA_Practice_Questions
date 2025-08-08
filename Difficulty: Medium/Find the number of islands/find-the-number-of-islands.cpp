class Solution {
  public:
    void bfs(vector<vector<char>> &grid , vector<vector<int>> &vis , vector<pair<int , int>> &dis , pair<int , int> node){
        int ni = node.first;
        int nj = node.second;
        
        vis[ni][nj] = 1;
        queue<pair<int , int>> q;
        q.push({ni , nj});
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(auto d : dis){
                int dx = d.first + i;
                int dy = d.second + j;
                
                if(dx>=0 && dy>=0 && dx<grid.size() && dy<grid[0].size() && !vis[dx][dy] && grid[dx][dy] == 'L'){
                    vis[dx][dy] = 1;
                    q.push({dx , dy});
                }
            }
        }
        
    }
    int countIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> vis(row , vector<int>(col , 0));
        vector<pair<int , int>> dis = {{0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1} , {-1 , -1} , {1 , -1 } , {-1 , 1} , {1 , 1}};
        int count = 0;
        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ; j<col ; j++){
                if(!vis[i][j] && grid[i][j] == 'L'){
                    bfs(grid , vis , dis , {i , j});
                    count++;
                }
            }
        }
        
        return count;
    }
};