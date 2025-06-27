class Solution {
public:

    int  fnBfs(vector<vector<int>>& grid , vector<vector<int>>& visited , queue<pair<int , int>> &rotten , vector<pair<int , int>> dec , int fCount ){

        int time = -1;

        while(!rotten.empty()){
            int size = rotten.size();
            for(int i = 0 ; i<size ; i++){
                auto rot = rotten.front();
                rotten.pop();
                for(auto d : dec){
                    int dx = d.first + rot.first;
                    int dy = d.second + rot.second;

                    if(dx>=0 && dy>=0 && dx<grid.size() && dy<grid[0].size() && !visited[dx][dy] && grid[dx][dy] == 1){
                        grid[dx][dy] = 2;
                        rotten.push({dx , dy});
                        visited[dx][dy] = 1;
                        fCount--;
                    }
                }
            }
            time++;


        }
            if(fCount != 0){
                return -1;
            }

            return time;
    }

    int orangesRotting(vector<vector<int>>& grid ) {

        int vertex = grid.size();
        int edge = grid[0].size();
        

        vector<vector<int>> vis(vertex , vector<int>(edge , 0));
        int freshCount = 0;
        queue<pair<int , int>> rotten;
        vector<pair<int , int>> dec = {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}};


        for(int i =0  ; i<vertex ; i++){
            for(int j = 0 ; j<edge ; j++){
                if(grid[i][j] == 1){
                    freshCount++;
                }
                else if(grid[i][j] == 2){
                    rotten.push({i , j});
                    vis[i][j] = 1;
                }
            }
        }
        if(freshCount == 0) return 0;

       return fnBfs(grid , vis , rotten , dec , freshCount);


        
    }
};