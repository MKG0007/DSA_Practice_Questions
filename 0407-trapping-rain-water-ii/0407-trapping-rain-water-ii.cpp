class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<int>> volume(m, vector<int>(n));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                volume[i][j] = heightMap[i][j];
            }
        }



        bool upt = true, init = true;
        while (upt){
            upt = false;
            for (int i = 1; i < m - 1; i++){
                for (int j = 1; j < n - 1; j++){
                    int val = max(heightMap[i][j], min(volume[i-1][j], volume[i][j - 1]));
                    if (init || volume[i][j] > val){
                        volume[i][j] = val;
                        upt = true;
                    }
                }
            }

            
            init = false;
            for (int i = m - 2; i >= 1; i--){
                for (int j = n - 2; j >= 1; j--){
                    int val = max(heightMap[i][j], min(volume[i+1][j], volume[i][j+1]));
                    if (volume[i][j] > val){
                        volume[i][j] = val;
                        upt = true;
                    }
                }
            }
        }
        int res = 0;
        for (int i = 1; i < m - 1; i++){
            for (int j = 1; j < n - 1; j++){
                if (volume[i][j] > heightMap[i][j]){
                    res += volume[i][j] - heightMap[i][j];
                }
            }
        }
        return res;
    }
};