class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        int maxi = 0;
        
        
        for (int i = 1; i < n; i++) {
            
            int temp = arr[i - 1] + arr[i];
            maxi = max(temp, maxi);
        }
        
        
        return maxi;
    }
};