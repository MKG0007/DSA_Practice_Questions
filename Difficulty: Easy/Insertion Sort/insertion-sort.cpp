class Solution {
  public:
    // Please change the array in-place
    void insertionSort(vector<int>& arr) {
        int size = arr.size();
        
        for(int i = 1 ; i<size ; i++){
            int crr = arr[i];
            int prev = i-1;
            
            while(prev >= 0 && arr[prev]>crr){
                arr[prev+1] = arr[prev];
                prev--;
            }
            arr[prev+1] = crr;
        }
        
    }
};