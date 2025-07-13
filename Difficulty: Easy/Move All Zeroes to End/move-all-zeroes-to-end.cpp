// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int size = arr.size();
        
        vector<int> temp(size , 0);
        int index = 0;
        for(int i = 0 ; i<size ; i++){
            if(arr[i] != 0){
                temp[index] = arr[i];
                index++;
            }
        }
        
        for(int i = 0 ; i<size ;i++){
            arr[i] = temp[i];
        }
    }
};