class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        vector<int> ans;
        
        int pro = 1;
        ans.push_back(pro);
        
        for(int i = 1 ; i<n ; i++){
            pro = pro*(n-i);
            pro = pro/i;
            ans.push_back(pro);
        }
        
        return ans;
    }
};
