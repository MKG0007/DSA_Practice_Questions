class Solution {
public:

    bool dfs(vector<vector<int>>& graph , vector<int> &vis , vector<int> &pvis , vector<int> &check , int node){
        vis[node] = 1;
        pvis[node] = 1;

        for(int i : graph[node]){
            if(!vis[i]){
                if(dfs(graph , vis , pvis , check , i) == true)return true;
            }
            else if(pvis[i]){
                return true;
            }
        }

        check[node] = 1;
        pvis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> vis(v , 0);
        vector<int> pvis(v , 0);
        vector<int> check(v , 0);
        vector<int> ans;

        for(int i = 0 ; i<v ; i++){
            if(!vis[i]){
                dfs(graph , vis , pvis , check , i);
            }
        }
        
        for(int i = 0 ; i<v ; i++){
            if(check[i] == 1){
                ans.push_back(i);
            }

        }
        return ans;
    }
};