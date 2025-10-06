class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<bool>> vis(n,vector<bool>(n,false));
        vector<vector<int>> dis(n,vector<int>(n,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        int dx[4]={0,0,-1,1}; int dy[4]={1,-1,0,0};
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=true;
        dis[0][0]=grid[0][0];


        while(!pq.empty())
        {
            auto top = pq.top(); pq.pop();
            int tm = top.first;
            int x = top.second.first; int y = top.second.second;
            dis[x][y]=tm;
            for(int i=0;i<4;i++){

                
                int x1 = x+dx[i]; int y1 = y+dy[i];
                if(x1>=0 && x1<n && y1>=0 && y1<n){
                    if(!vis[x1][y1]){
                        int t = grid[x1][y1];
                        int actual = max(t,tm);
                        vis[x1][y1]=true;
                        pq.push({actual,{x1,y1}});
                    }
                }
            }
        }

        return dis[n-1][n-1];
        
    }
};