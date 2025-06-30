class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int row = image.size();
        int col = image[0].size();
        
        
        vector<vector<int>> vis(row , vector<int>(col , 0));
        int originalColor = image[sr][sc];
        image[sr][sc] = newColor;
        queue<pair<int , int>> q;
        q.push({sr , sc});
        
        vector<pair<int , int>> dec = {{0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1}};
        vis[sr][sc] = 1;
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(auto d : dec){
                int di = i + d.first;
                int dj = j + d.second;
                
                if(di>=0 && dj>=0 && di<row && dj<col && !vis[di][dj] && image[di][dj] == originalColor){
                    vis[di][dj] = 1;
                    image[di][dj] = newColor;
                    q.push({di , dj});
                }
            }
        }
        
        return image;
    }
};