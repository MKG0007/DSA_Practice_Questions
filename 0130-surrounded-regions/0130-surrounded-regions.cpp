class Solution {
public:
  void fnDfs(vector<vector<char>> &mat , vector<vector<int >> &vis , vector<pair<int , int>> &d ,  int i , int j){
      vis[i][j] = 1;
      
      for(auto dd : d){
          int di = dd.first + i;
          int dj = dd.second + j;
          
          if(di>=0 && di<mat.size() && dj>=0 && dj<mat[0].size() && !vis[di][dj] && mat[di][dj] == 'O'){
               fnDfs(mat , vis , d , di , dj);
          }
      }
  }
    void solve(vector<vector<char>>& mat) {
         
        int vertex = mat.size();
        int edge = mat[0].size();
        vector<vector<int>> vis(vertex , vector<int>(edge , 0));
        vector<pair<int , int>> d = { {1 , 0}  , {0 , 1} , {-1 , 0} , {0 , -1}};
        for(int i = 0 ; i<vertex ; i++){
            for(int j = 0 ; j<edge ; j++){
                if(i == 0 || j == 0 || i == vertex-1 || j == edge-1){
                    if(!vis[i][j] && mat[i][j] == 'O'){
                        fnDfs(mat , vis , d , i , j);
                    }
                }
            }
        }
        
        for(int i = 0 ; i<vertex ; i++){
            for(int j = 0  ; j<edge ; j++){
                if(!vis[i][j]  && mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
            }
        }
        
    }
};