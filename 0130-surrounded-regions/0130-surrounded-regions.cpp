class Solution {
public:
    void solve(vector<vector<char>>& adj) {
        int row = adj.size();
        int col = adj[0].size();
        vector<vector<int>> vis(row , vector<int>(col , 0));
        vector<pair<int , int>> dec = {{0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1}};

        queue<pair<int , int>> q;
        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ; j<col ; j++){
                if(i == 0 || i == row-1 || j == 0 || j == col-1){
                    if(adj[i][j] == 'O'){
                        q.push({i , j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            for(auto d : dec){
                int di = d.first + node.first;
                int dj = d.second + node.second;

                if(di>=0 && dj>=0 && di<row && dj<col && !vis[di][dj] && adj[di][dj] == 'O'){
                    vis[di][dj] = 1;
                    q.push({di , dj});
                }
            }
        }


        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ; j<col ; j++){
                if(!vis[i][j] && adj[i][j] == 'O'){
                    adj[i][j] = 'X';
                }
            }
        }  
        
    }
};