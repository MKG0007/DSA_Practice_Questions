class Solution {
public:

    bool dfs(vector<vector<int>>& graph , vector<int> &vis , vector<int> &path , int node){
        vis[node] = 1;
        path[node] = 1;

        for(int i : graph[node]){
            if(!vis[i]){
                if(dfs(graph , vis , path , i)) return true; 
            }
            else if(path[i] == 1) return true;
        }

        path[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();

        vector<int> vis(v , 0);
        vector<int> path(v, 0);
        vector<int> ans;

        for(int i = 0 ; i<v ; i++){
            if(!vis[i]){
                dfs(graph , vis , path, i);
            }
        }
        for(int i = 0 ; i<v ; i++){
            if(path[i] == 0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};