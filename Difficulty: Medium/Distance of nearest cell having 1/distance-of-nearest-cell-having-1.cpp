class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        
        int vertex = grid.size();
        int edges = grid[0].size();
        vector<vector<int>> vis(vertex , vector<int>(edges , 0));
        vector<vector<int>> dis(vertex , vector<int>(edges , 0));
        vector<pair<int , int>> d = {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}};
        queue<pair<pair<int , int> , int>> q;
        
        for(int i = 0 ; i<vertex ; i++){
            for(int j = 0 ; j<edges ; j++){
                if(grid[i][j] == 1){
                    vis[i][j] = 1;
                    q.push({{i , j} , 0});
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            
            for(auto dd : d){
                int di = dd.first + i;
                int dj = dd.second + j;
                
                if(di>=0 && dj>=0 && di<vertex && dj<edges && !vis[di][dj]){
                    vis[di][dj] = 1;
                    dis[di][dj] = steps+1;
                    q.push({{di , dj} , steps+1});
                }
            }
        }
        
        return dis;
    }
};