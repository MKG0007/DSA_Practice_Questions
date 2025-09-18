class Solution {
public:
    void row(vector<int> &ans , int rowIndex){
        int res = 1;
        ans.push_back(res);

        for(int i = 1 ; i<rowIndex ; i++){
            res = res*(rowIndex-i);
            res = res/i;
            ans.push_back(res);
        }
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i = numRows-1 ; i>=0 ; i--){
            vector<int> temp ;
            row(temp , numRows-i);
            ans.push_back(temp);

        }

        return ans;
        
    }
};