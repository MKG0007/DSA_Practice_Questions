class Solution {
public:
  
  void row(vector<int> &ans , int num){
      int res = 1;
      ans.push_back(res);
      
      for(int i = 1 ; i<num ; i++){
          res = res*(num-i);
          res = res/i;
          ans.push_back(res);
      }
      
  }
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        row(ans , rowIndex+1);
        return ans;
    }
};