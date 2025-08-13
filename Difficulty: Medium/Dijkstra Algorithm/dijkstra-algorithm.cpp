// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        unordered_map<int , vector<pair<int , int>>> adj;
        
        for(auto ele : edges){
            adj[ele[0]].push_back({ele[1] , ele[2]});
        }
        
        vector<int> ans(V , 1e9);
        
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>>pq;
        pq.push({0 , src});
        ans[src] = 0;
        
        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            
            for(auto ele : adj[node]){
                int e = ele.first;
                int w = ele.second;
                if(wt+w<ans[e]){
                    ans[e] = w+wt;
                    pq.push({ans[e] , e});
                }
            }
        }
        
        return ans;
        
    }
};