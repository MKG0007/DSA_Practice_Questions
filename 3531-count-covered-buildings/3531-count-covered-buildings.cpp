class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& blds) {
        unordered_map<int, set<int>> mapx;
        unordered_map<int, set<int>> mapy;
        

        for (auto& v : blds) {
            mapx[v[0]].insert(v[1]);
            mapy[v[1]].insert(v[0]);
        }

        int res = 0;
        for (auto& v : blds) {
            int xsize = mapx[v[0]].size();
            int ysize = mapy[v[1]].size();
            
            if (xsize <= 2 || ysize <= 2) continue;
            if (*mapx[v[0]].begin() == v[1] || *mapx[v[0]].rbegin() == v[1]) continue;
            if (*mapy[v[1]].begin() == v[0] || *mapy[v[1]].rbegin() == v[0]) continue;
            res++; 
        }

        return res;
    }
};