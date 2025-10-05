// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        int size = arr.size();
        if(size<k || k<0) return -1;
        sort(arr.begin() , arr.end());
        
        return arr[k-1];
        
    }
};