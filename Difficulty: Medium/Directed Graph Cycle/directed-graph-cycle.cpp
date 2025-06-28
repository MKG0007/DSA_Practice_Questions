class Solution {
  public:
  bool dfs(vector<vector<int>> &adj, vector<int> &vis, vector<int> &pvis, int node) {
      vis[node] = 1;
      pvis[node] = 1;

      for (int neighbor : adj[node]) {
          if (!vis[neighbor]) {
              if (dfs(adj, vis, pvis, neighbor)) return true;
          } else if (pvis[neighbor]) {
              return true; // back edge found
          }
      }

      pvis[node] = 0; // backtrack
      return false;
  }

  bool isCyclic(int V, vector<vector<int>> &edges) {
      // Step 1: Create adjacency list from edge list
      vector<vector<int>> adj(V);
      for (auto &edge : edges) {
          int u = edge[0], v = edge[1];
          adj[u].push_back(v);
      }

      // Step 2: DFS cycle detection
      vector<int> vis(V, 0), pvis(V, 0);

      for (int i = 0; i < V; i++) {
          if (!vis[i]) {
              if (dfs(adj, vis, pvis, i)) {
                  return true;
              }
          }
      }

      return false;
  }
};
