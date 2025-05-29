class Solution {
private:
    vector<int> dist;
    pair<int, int> dfs(int u, int p, int d, vector<vector<int>>& g) {
        int e = 1, o = 0;
        dist[u] = d;
        for (auto& v : g[u]) {
            if (v == p)
                continue;
            auto [e1, o1] = dfs(v, u, d ^ 1, g);
            e += e1;
            o += o1;
        }
        return {o, e};
    }
    vector<int> getCount(vector<vector<int>>& edges, int sign) {
        int n = edges.size() + 1;
        dist.resize(n, 0);
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        auto [odd, even] = dfs(0, -1, 0, g);
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            int op = (sign ^ dist[i]);
            res[i] = (op == 0) ? even : odd;
        }
        return res;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        auto count1 = getCount(edges1, 0);
        auto count2 = getCount(edges2, 1);
        int mx2 = 0, n = edges1.size() + 1;
        for (auto& x : count2)
            mx2 = max(mx2, x);
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            res[i] = count1[i] + mx2;
        }
        return res;
    }
};