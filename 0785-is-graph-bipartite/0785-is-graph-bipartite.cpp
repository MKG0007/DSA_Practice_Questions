class Solution {
public:

    bool bfs(vector<vector<int>>& graph , vector<int> &color , int node){
        color[node] = 1;
        queue<int> q;
        q.push(node);

        while(!q.empty()){
            int n = q.front();
            q.pop();

            for(int ele : graph[n]){
                if(color[ele] == -1){
                    (color[n] == 1)? color[ele] = 0 : color[ele] = 1;
                    q.push(ele);
                }
                else if(color[ele] == color[n]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();

        vector<int> color(v , -1);
        for(int i = 0 ; i<v ; i++){
            if(color[i] == -1){
                if(bfs(graph , color , i) == false) return false;
            }
        }

        return true;

        
    }
};