// User function Template for C++

class Solution {
  public:
    // Function to check if we can reach the last index from 0th index.
    bool canReach(vector<int> &arr) {
        // code here
        int size = arr.size();
        int index = 0;
        
        for(int i = 0 ; i<size ; i++){
            if(i>index) return false;
            
            index = max(index , i+arr[i]);
        }
        return true;
    }
};