// User function Template for C++
class Solution {
  public:
    vector<vector<int> > getSubArrays(vector<int>& arr) {
        int size = arr.size();
        vector<vector<int>> ans;
        
        for(int start = 0 ; start<size ; start++){
            for(int end = start ; end<size ; end++){
                vector<int> tamp;
                for(int i = start ; i<=end ; i++){
                    tamp.push_back(arr[i]);
                }
                ans.push_back(tamp);
            }
        }
        
        return ans;
        
    }
};