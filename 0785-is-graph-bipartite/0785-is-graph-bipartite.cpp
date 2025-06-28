class Solution {
public:

    bool bfs(vector<vector<int>>& gph , vector<int>& vis , int node){
        vis[node] = 1;
        queue<int> q;
        q.push(node);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int ele : gph[node]){
                if(vis[ele] == -1){
                    int gcolor = -1;
                    if(vis[node] == 1) gcolor = 0;
                    else gcolor = 1;

                    vis[ele] = gcolor;
                    q.push(ele);
                }
                else if(vis[ele] == vis[node]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& gph) {
        int row = gph.size();
        int col = gph[0].size();

        vector<int> vis(row , -1);

        for(int i = 0  ; i<row ; i++){
                if(vis[i] == -1){
                    if(bfs(gph , vis , i) == false) return false;

                
            }
        }

        return true;
        
    }
};