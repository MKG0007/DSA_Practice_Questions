class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        int size = arr.size();
        d = d%size;
        
        vector<int> temp;
        
        for(int i = 0 ; i<d ; i++){
            temp.push_back(arr[i]);
        }
        
        for(int i = d ; i<size ; i++){
            arr[i-d] = arr[i];
        }
        
        for(int i = size-d ; i<size ; i++){
            arr[i] = temp[i-(size-d)];
        }
        
        
    }
};