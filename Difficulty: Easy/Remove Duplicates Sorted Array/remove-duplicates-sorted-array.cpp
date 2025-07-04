class Solution {
  public:
    int removeDuplicates(vector<int> &arr) {
        int size = arr.size();
        int j = 0;
        for(int i =0 ; i<size ; i++){
            if(arr[j] != arr[i]){
                arr[j+1] = arr[i];
                j++;
            }
        }
        
        return j+1;
    }
};