class Solution {
public:


    void fndfs(unordered_map<int , vector<int>>& adj , int node , vector<int> &visited){
        visited[node] = 1;

        for(int i : adj[node]){
            if(!visited[i]){
             fndfs(adj , i , visited);   
            }
        }



    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int vertex = isConnected.size();
        int edges = isConnected[0].size();

        unordered_map<int , vector<int>> adj;
        vector<int> visited(vertex , 0);

        for(int i = 0 ; i<vertex ; i++){
            for(int j = 0 ; j<edges ; j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;

        for(int i = 0 ; i<vertex ; i++){
            if(!visited[i]){
                fndfs(adj , i , visited);
                count++;
            }
        }
        return count;
    }
};