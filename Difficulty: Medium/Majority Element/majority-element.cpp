class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int size = arr.size();
        int crr = -1;
        int count = 0;
        
        for(int i = 0 ; i<size ; i++){
            if(count == 0){
                count = 1;
                crr = arr[i];
            }
            else if(crr == arr[i]){
                count++;
            }
            else{
                count--;
            }
        }
        
        
        count = 0;
        
        for(int i = 0 ; i<size ; i++){
            if(crr == arr[i]){
                count++;
            }
        }
        
        if(count>size/2) return crr;
        
        return -1;
        
    }
};