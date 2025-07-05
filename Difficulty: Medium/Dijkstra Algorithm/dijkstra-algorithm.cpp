// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        unordered_map<int , vector<pair<int , int>>> adj;
        
        for(auto ele : edges){
            int u = ele[0];
            int v = ele[1];
            int w = ele[2];
            
            adj[u].push_back({v , w});
            adj[v].push_back({u , w});
        }
        
        vector<int> dis(V , 1e9);
        dis[src] = 0;
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        pq.push({0 , src});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int nw = pq.top().first;
            pq.pop();
            for(auto ele : adj[node]){
                int nele = ele.first;
                int wele = ele.second;
                if((nw+wele) < dis[nele]){
                    dis[nele] = nw+wele;
                    pq.push({dis[nele] , nele});
                }
            }
        }
        
        return dis;
        
    }
};