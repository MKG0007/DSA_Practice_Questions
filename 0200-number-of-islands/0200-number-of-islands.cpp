class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<int>> &vis, int i, int j,
             vector<pair<int, int>>& dec) {
        vis[i][j] = 1;

        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty()) {
            int ni = q.front().first;
            int nj = q.front().second;
            q.pop();

            for (auto d : dec) {
                int di = ni + d.first;
                int dj = nj + d.second;
                if (di >= 0 && dj >= 0 && di < grid.size() &&
                    dj < grid[0].size() && !vis[di][dj] &&
                    grid[di][dj] == '1') {
                    vis[di][dj] = 1;
                    q.push({di, dj});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<pair<int, int>> dec = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        vector<vector<int>> vis(row, vector<int>(col, 0));
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {

                    bfs(grid, vis, i, j, dec);
                    count++;
                }
            }
        }
        return count;
    }
};