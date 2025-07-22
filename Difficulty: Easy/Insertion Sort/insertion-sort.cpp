class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        // code here
        
        int size = arr.size();
        
        for(int i = 0 ; i<size ; i++){
            
            int j = i;
            
            while(j>0 && arr[j-1] > arr[j]){
                swap(arr[j-1] , arr[j]);
                j--;
            }
            
        }
    }
};