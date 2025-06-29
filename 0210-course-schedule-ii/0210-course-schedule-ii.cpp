class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& edges) {
        unordered_map<int , vector<int>> adj;
        int v = numCourses;
        
        for(auto edge : edges){
            int v = edge[0];
            int u = edge[1];
            
            adj[u].push_back(v);
        }
        
        vector<int> in(v , 0);
        vector<int> ans;
        queue<int> q;
        
        for(int i = 0 ; i<v ; i++){
            for(auto ele : adj[i]){
                in[ele]++;
            }
        }
        
        for(int i = 0 ; i<v ; i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            
            q.pop();
            ans.push_back(node);
            
            for(int ele : adj[node]){
                in[ele]--;
                if(in[ele] == 0) q.push(ele);
            }
        }
        
        if(ans.size() == v){
            return ans;
        }
        return {};
        
    }
};