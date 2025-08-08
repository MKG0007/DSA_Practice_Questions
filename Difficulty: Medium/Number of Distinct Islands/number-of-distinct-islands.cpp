// User function Template for C++

class Solution {
  public:
    void bfs(vector<vector<int>> &grid , set<vector<pair<int , int>>> &ans , vector<vector<int>> &vis , pair<int , int> node){
        int ni = node.first;
        int nj = node.second;
        
        vis[ni][nj] = 1;
        queue<pair<int , int>> q;
        q.push({ni , nj});
        vector<pair<int , int>> dis = {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}};
        vector<pair<int , int>> temp;
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            temp.push_back({i-ni , j-nj});
            q.pop();
            
            for(auto d : dis){
                int dx = d.first + i;
                int dy = d.second + j;
                
                if(dx>=0 && dy>=0 && dx<grid.size() && dy<grid[0].size() && !vis[dx][dy] && grid[dx][dy] == 1){
                    vis[dx][dy] = 1;
                    q.push({dx , dy});
                }
            }
            
        }
        ans.insert(temp);
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        set<vector<pair<int , int>>> ans;
        vector<vector<int>> vis(row , vector<int>(col , 0));
        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ; j<col ; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    bfs(grid  , ans , vis , {i , j});
                }
            }
        }
        
        return ans.size();
        
    }
};
