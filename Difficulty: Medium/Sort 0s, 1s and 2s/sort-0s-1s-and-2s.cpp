class Solution {
  public:
    void sort012(vector<int>& arr) {
        int size = arr.size();
        
        int high = size-1;
        int low = 0 ; 
        int mid = 0 ;
        
        while(mid<=high){
            if(arr[mid] == 0){
                swap(arr[mid] , arr[low]);
                low++;
                mid++;
            }
            else if(arr[mid] == 1){
                mid++;
            }
            else{
                swap(arr[mid] , arr[high]);
                    high--;
            }
        }
        
    }
};