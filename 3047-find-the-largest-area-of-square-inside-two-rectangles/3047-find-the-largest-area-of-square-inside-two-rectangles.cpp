class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {

        int n = bottomLeft.size();
        long long maxSquare = 0;
        for (int i = 0; i < n - 1; i++){
            for (int j = i + 1; j < n; j++){
                long long min_x = max(bottomLeft[i][0], bottomLeft[j][0]);
                long long max_x = min(topRight[i][0], topRight[j][0]);
                long long min_y = max(bottomLeft[i][1], bottomLeft[j][1]);
                long long max_y = min(topRight[i][1], topRight[j][1]);
                if (min_x < max_x && min_y < max_y){
                    long long square = min(max_x - min_x, max_y - min_y);
                    maxSquare = max(maxSquare, square * square);
                }
            }
        }
        return maxSquare;
    }
};
