// User function Template for C++
class Solution {
  public:
  
  void dfs(unordered_map<int , vector<pair<int , int>>> &adj , vector<int> &vis , stack<int> &st , int node){
      vis[node] = 1;
      
      for(auto ele : adj[node]){
          if(!vis[ele.first]){
              dfs(adj , vis , st , ele.first);
          }
      }
      
      st.push(node);
  }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
            unordered_map<int , vector<pair<int , int>>> adj;
            
            for(auto ele : edges){
                int u = ele[0];
                int v = ele[1];
                int w = ele[2];
                adj[u].push_back({v , w});
            }
            vector<int> vis(V , 0);
            stack<int> st;
            
            for(int i =0 ; i<V ; i++){
                if(!vis[i]){
                    dfs(adj , vis , st , i);
                }
            }
            
            vector<int> dis(V , 1e9);
            dis[0] = 0;
            
            while(!st.empty()){
                int n = st.top();
                st.pop();
                for(auto ele : adj[n]){
                    if((dis[n] + ele.second) < dis[ele.first]){
                        dis[ele.first] = dis[n] + ele.second;
                    }
                }
            }
            
            for(int i = 0 ; i<V ; i++){
                if(dis[i] == 1e9){
                    dis[i] = -1;
                }
            }
            
            return dis;
        
    }
};
