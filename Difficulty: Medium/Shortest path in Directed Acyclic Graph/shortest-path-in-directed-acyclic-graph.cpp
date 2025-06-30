// User function Template for C++
class Solution {
  public:
  
    void dfs(unordered_map<int , vector<pair<int , int>>> &adj , stack<int> &st , vector<int> &vis , int node){
        vis[node] = 1;
        
        for(auto ele : adj[node]){
            int n = ele.first;
            if(!vis[n]){
                dfs(adj , st , vis , n);
            }
        }
        
        st.push(node);
        
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        unordered_map<int , vector<pair<int , int>>> adj;
        vector<int> vis(V , 0);
        stack<int> st;
        
        for(int i = 0 ; i<E ; i++){
                int u = edges[i][0];
                int v = edges[i][1];
                int w = edges[i][2];
                
                adj[u].push_back({v , w});
        }
        
        vector<int> dis(V , INT_MAX);
        dis[0] = 0;
        for(int i = 0 ; i<V ; i++){
                if(!vis[i]){
                    dfs(adj , st ,vis ,  i);
                }
        }
        
        
        
        while(!st.empty()){
            int i = st.top();
            st.pop();
            
            for(auto ele : adj[i]){
                int n = ele.first;
                int w = ele.second;
                if(dis[i] != INT_MAX && (dis[i] + w) < dis[n]){
                    dis[n] = dis[i] + w;
                }
            }
        }
        
        for(int i = 0 ; i<V ; i++){
            if(dis[i] == INT_MAX){
                dis[i] = -1;
            }
        }        
        return dis;
    }
};
