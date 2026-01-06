class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int size = arr.size();
        int crr = 0;
        for(int i = 0 ; i<k ; i++){
            crr ^= arr[i];
        }
        int ans = crr;
        for(int i = k ; i<size ; i++){
            crr ^= arr[i-k];
            crr ^= arr[i];
            ans = max(ans , crr);
        }
        
        return ans;
        
        
    }
};