class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        int size = arr.size();
        
        for(int i = 0 ; i<size-1 ; i++){
            int check = true;
            for(int j = 1 ; j<size-i ; j++){
                if(arr[j]<arr[j-1]) swap(arr[j] , arr[j-1]), check = false;
            }
            if(check){
                break;
            }
        }
    }
};