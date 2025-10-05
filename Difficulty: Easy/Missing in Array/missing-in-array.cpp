class Solution {
  public:
    int missingNum(vector<int>& arr) {
        
        int n = arr.size();
        sort(arr.begin() , arr.end());
      
        for(int i = 0; i < n; i++){
            if(arr[i] != i+1){
                return i+1;
            }
        }
        return arr[n-1]+1;
        
        // code here
        
    }
};