class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int size = arr.size();
        int total = 0;
        
        vector<int> left(size , 0);
        vector<int> right(size , 0);
        left[0] = arr[0];
        right[size-1] = arr[size-1];
        
        for(int i = 1 ; i<size ; i++){
            left[i] = max(left[i-1] , arr[i]);
        }
        for(int i = size-2; i>=0 ; i--){
            right[i] = max(right[i+1] , arr[i]);
        }
        
        for(int i = 0 ; i<size ; i++){
            
            total += min(left[i] , right[i])-arr[i];
        }
        
        return total;
        
    }
};