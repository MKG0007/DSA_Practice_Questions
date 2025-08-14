// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> s,
                     pair<int, int> des) {
        // code here
        if(grid[s.first][s.second] == 0 || grid[des.first][des.second] == 0) return -1;
       int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dis(row , vector<int>(col , 1e9));
        dis[s.first][s.second] = 0;
        queue<vector<int>> q;

        q.push({s.first , s.second , 0});
        vector<pair<int , int>> dec = {{0  , 1} , {1 , 0} , {-1 , 0} , {0 , -1}};

        while(!q.empty()){
            int i = q.front()[0];
            int j = q.front()[1];
            int w = q.front()[2];
            q.pop();

            if(i == des.first && j == des.second) return w;
            for(auto d : dec){
                    int dx = i+d.first;
                    int dy = j+d.second;
                    int wt = w+1;
                    if(dx<row && dy<col && dx>=0 && dy>=0 && grid[dx][dy] == 1 && wt<dis[dx][dy]){                 
                        dis[dx][dy] = wt;
                        q.push({dx , dy , wt});
                    }
                
            }
        }

        return -1;


        
    
    }
};
