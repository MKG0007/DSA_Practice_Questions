class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        map<int, vector<vector<int>>> m;

        
        for (auto i : edges) {
            m[i[0]].push_back({i[2], i[1]});        
            m[i[1]].push_back({2 * i[2], i[0]});    
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> dist(n, INT_MAX);

        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();

            int currDist = temp[0];
            int u = temp[1];

            if (currDist > dist[u]) continue;

            for (auto &i : m[u]) {
                int d = i[0];
                int v = i[1];

                if (dist[v] > currDist + d) {
                    dist[v] = currDist + d;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1] == INT_MAX ? -1 : dist[n - 1];
    }
};