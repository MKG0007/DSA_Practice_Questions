class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        // code here
        int size = arr.size();
        for(int i = 0 ; i<size-1 ; i++){
            int small_index = i;
            for(int j = i+1 ; j<size ; j++){
                if(arr[small_index] > arr[j]){
                    small_index = j;
                }
            }
            swap(arr[small_index] , arr[i]);
        }
    }
};