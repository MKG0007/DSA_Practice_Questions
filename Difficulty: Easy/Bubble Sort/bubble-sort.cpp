class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(vector<int>& arr) {
        int size = arr.size();
        
        for(int i = 0 ; i<size-1 ; i++){
            for(int j = 0 ; j<size-i-1 ; j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j] , arr[j+1]);
                }
            }
        }
        
    }
};