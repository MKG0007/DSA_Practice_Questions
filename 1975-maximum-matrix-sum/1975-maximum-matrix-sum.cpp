class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& arr) {
        int row = arr.size();
        int col = arr[0].size();

        long long sum = 0;
        int negCount = 0;
        int minAbs = INT_MAX;

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(arr[i][j] < 0) negCount++;
                sum += abs(arr[i][j]);
                minAbs = min(minAbs, abs(arr[i][j]));
            }
        }

        if(negCount % 2 == 1)
            sum -= 2LL * minAbs;

        return sum;
    }
};
