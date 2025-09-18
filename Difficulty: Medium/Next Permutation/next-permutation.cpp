class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int size = arr.size();
        int index = -1;
        
        for(int i = size-2 ; i>=0 ; i--){
            if(arr[i]<arr[i+1]){
                index = i;
                break;
            }
        }
        
        if(index == -1){
            reverse(arr.begin() , arr.end());
            return;
        }
        
        for(int i = size-1 ; i>index ; i--){
            if(arr[index]<arr[i]){
                swap(arr[index] , arr[i]);
                break;
            }
        }
        
        sort(arr.begin()+index+1 , arr.end());
        
        
    }
};