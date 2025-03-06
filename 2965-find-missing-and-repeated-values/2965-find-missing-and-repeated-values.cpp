class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int> s;
        int n = grid.size();
        int exsum = (n*n)*((n*n) + 1)/2;
        int asum = 0;

        int a , b;

        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                asum += grid[i][j];

                if(s.find(grid[i][j]) != s.end()){
                    a = grid[i][j];
                }
                s.insert(grid[i][j]);


            }
        }
        b = (exsum+a) - asum;
        return {a , b};
    }
};