//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    void bfs(vector<vector<int>> &adj , vector<int> &vis , vector<int> &ans , int node){
        vis[node] = 1;
        
        queue<int> q;
        q.push(node);
        
        while(!q.empty()){
            int n = q.front();
            ans.push_back(n);
            q.pop();
            
            for(auto ele : adj[n]){
                if(!vis[ele]){
                    vis[ele] = 1;
                    q.push(ele);
                }
            }
        }
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        int vertex = adj.size();
        vector<int> vis(vertex , 0);
        vector<int> ans;
        
        for(int i = 0 ; i<vertex ; i++){
            if(!vis[i]){
                bfs(adj , vis , ans , i);
            }
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        // Use vector of vectors instead of array of vectors.
        vector<vector<int>> adj(V);

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.bfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends