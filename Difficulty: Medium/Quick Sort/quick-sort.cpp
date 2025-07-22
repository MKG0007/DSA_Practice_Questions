class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        if(low<high){
            int part_index = partition(arr , low , high);
            
            quickSort(arr , low , part_index-1);
            quickSort(arr , part_index+1 , high);
        }
        
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        int pivot = low;
        int i = low ;
        int j = high;
        while(i<j){
            while(arr[i]<=arr[pivot] && i<high) i++;
            while(arr[j]>arr[pivot] && j>low) j--;
            
            if(i<j) swap(arr[i] , arr[j]);
        }
        swap(arr[pivot] , arr[j]);
        return j;
        // code here
    }
};