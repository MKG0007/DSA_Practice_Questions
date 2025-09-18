class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int size = arr.size();
        int maxi = INT_MIN;
        int sum = 0 ;
        for(int i = 0 ; i<size ; i++){
            sum += arr[i];
            maxi = max(maxi , sum);
            
            if(sum <0) sum = 0;
            
        }
        
        
        return maxi;
        
    }
};