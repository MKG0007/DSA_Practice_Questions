class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int row = graph.size();

        unordered_map<int , vector<int>> adj;
        vector<int> in(row , 0);
        queue<int> q;
        vector<int> ans;

        for(int i = 0 ; i<row ; i++){
            for(auto ele : graph[i]){
                adj[ele].push_back(i);
            }
        }

        for(int i = 0 ; i<row ; i++){
            for(int ele : adj[i]){
                in[ele]++;
            }
        }
        for(int i = 0 ; i<row ; i++){
            if(in[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);

            q.pop();
            for(int ele : adj[node]){
                in[ele]--;
                if(in[ele] == 0) q.push(ele);
            }
        }

        sort(ans.begin() , ans.end());

        return ans;

    }
};