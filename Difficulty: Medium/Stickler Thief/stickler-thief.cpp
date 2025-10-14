class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int size = arr.size();
        
        int prev = arr[0];
        int prev2 = 0;
        
        for(int i = 1 ; i<size ; i++){
            int pick = arr[i];
            
            if(i>1) pick += prev2;
            int npick = 0 + prev;
            
            int crr = max(pick , npick);
            
            prev2 = prev;
            prev = crr;
            
        }
        
        return prev;
    }
};