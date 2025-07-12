// User function Template for C++

class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        int size = arr.size();
        
        for(int i = size-2 ; i>=0 ; i--){
            swap(arr[i] , arr[i+1]);
        }
        
        
    }
};