class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        int size = arr.size();
        int minNum = INT_MAX;
        int maxNum = INT_MIN;
        
        for(int i = 0 ; i<size ; i++){
            minNum = min(minNum , arr[i]);
            maxNum = max(maxNum , arr[i]);
        }
        
        return {minNum , maxNum};
        
    }
};