class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> rowSum(r + 1, vector<int>(c + 1, 0));
        vector<vector<int>> colSum(r + 1, vector<int>(c + 1, 0));
        vector<vector<int>> diag(r + 1, vector<int>(c + 1, 0));
        vector<vector<int>> antidiag(r + 1, vector<int>(c + 1, 0));
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                int x = grid[i][j];
                rowSum[i + 1][j + 1] = rowSum[i + 1][j] + x;
                colSum[i + 1][j + 1] = colSum[i][j + 1] + x;
                diag[i + 1][j + 1] = diag[i][j] + x;
                antidiag[i + 1][j] = antidiag[i][j + 1] + x;
            }
        }
        auto isMagic = [&](int k) -> bool{
            for (int i = 0; i <= r - k; i++){
                for (int j = 0; j <= c - k; j++){
                    int s = diag[i + k][j + k] - diag[i][j];
                    int anti = antidiag[i + k][j] - antidiag[i][j + k];
                    if (s != anti)
                        continue;
                    bool valid = true;
                    for (int m = 0; m < k; m++){
                        int row = rowSum[i + m + 1][j + k] - rowSum[i + m + 1][j];
                        int col = colSum[i + k][j + m + 1] - colSum[i][j + m + 1];
                        if (row != s || col != s){
                            valid = false;
                            break;
                        }
                    }
                    if (valid)
                        return true;
                }
            }
            return false;
        };
        for (int k = min(r, c); k >= 2; k--){
            if (isMagic(k))
                return k;
        }
        return 1;
    }
};