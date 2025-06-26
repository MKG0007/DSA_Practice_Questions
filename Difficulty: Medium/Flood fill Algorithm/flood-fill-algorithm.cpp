class Solution {
  public:
  
  void fnDfs(vector<vector<int>>& image , int sr, int sc, int newColor , vector<vector<int>> &visited , int oldColor){
                                      visited[sr][sc] = 1;
                                      image[sr][sc] = newColor;
                                      vector<pair<int , int>> d = {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}};
                                      
                                      for(auto dd : d){
                                          int di  = dd.first+sr;
                                          int dj = dd.second+sc;
                                          
                                          if(di>=0 && di<image.size() && dj>=0 && dj<image[0].size() && !visited[di][dj] && image[di][dj] == oldColor){
                                              fnDfs(image , di , dj , newColor , visited , oldColor);
                                          }
                                      }
                                      
                                  }
  
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int vertex = image.size();
        int edge = image[0].size();
        vector<vector<int>> visited(vertex , vector<int>(edge , 0));
        
        int oldColor = image[sr][sc];
        
        fnDfs(image , sr , sc , newColor , visited , oldColor);
        
        
        return image;
        
        
    }
};