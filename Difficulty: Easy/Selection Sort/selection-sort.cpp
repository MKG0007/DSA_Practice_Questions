class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        int size = arr.size();
        
        for(int i = 0 ; i<size-1 ; i++){
            for(int j = i+1 ; j<size ; j++){
                if(arr[i]>arr[j]){
                    swap(arr[i] , arr[j]);
                }
            }
        }
        
    }
};