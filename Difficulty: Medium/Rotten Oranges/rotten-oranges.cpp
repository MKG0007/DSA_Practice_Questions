class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        vector<vector<int>> vis(row , vector<int>(col , 0));
        vector<pair<int , int>>dec = {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}};
        queue<pair<int , int>> q;
        int total = 0;
        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ; j<col ; j++){
                
                if(mat[i][j] == 2){
                    q.push({i , j});
                    
                }
                if(mat[i][j] == 1) total++;
                
            }
        }
        
        if(total == 0) return 0;
        
        int time = -1;
        while(!q.empty()){
            int size = q.size();
            time++;
            for(int i = 0 ; i<size ; i++){
                auto ele  = q.front();
                q.pop();
                vis[ele.first][ele.second] = 1;
                for(auto d : dec){
                    int dx = d.first + ele.first;
                    int dy = d.second + ele.second;
                    
                    if(dx>=0 && dy>=0 && dx<row && dy<col && !vis[dx][dy] && mat[dx][dy] == 1){
                        total--;
                        mat[dx][dy] = 2;
                        vis[dx][dy] = 1;
                        q.push({dx , dy});
                    }
                }
                
            }
        }
        
        if(total != 0){
            return -1;
        }
        
        return time;
        
    }
};