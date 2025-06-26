class Solution {
public:
    void fnBfs(vector<vector<char>>& grid , pair<int , int> node, vector<vector<int>>& visited){
        visited[node.first][node.second] = 1;

        vector<pair<int , int>> d = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

        queue<pair<int , int>> q;
        q.push(node);

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            for(auto dd : d){
                int di = dd.first+node.first;
                int dj = dd.second+node.second;
                if(di>=0 && di<grid.size() && dj>=0 && dj<grid[0].size() && !visited[di][dj]){
                    if(grid[di][dj] == '1'){
                    q.push({di , dj});
                    }
                    visited[di][dj] = 1;
                }
            }
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int vertex = grid.size();
        int edge = grid[0].size();
        vector<vector<int>> visited(vertex , vector<int>(edge , 0));
        int count = 0;
        for(int i = 0 ; i<vertex ; i++){
            for(int j = 0 ; j<edge ; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    fnBfs(grid , {i , j} , visited);
                    count++;

                }
            }
        }

        return count;
        
    }
};