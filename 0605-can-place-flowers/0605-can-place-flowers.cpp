class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        int size = arr.size();
        vector<int> visited(size , 0);


        for(int i = 0 ; i<size ; i++){
            if(arr[i] == 1){
                visited[i] = 1;
                if(i-1>=0 && i-1<size){
                    visited[i-1] = 1;
                }
                if(i+1>=0 && i+1<size){
                    visited[i+1] = 1;
                }
            }   
        }

        int count = 0 ;
        for(int i = 0 ; i<size ; i++){
            if(!visited[i]){
                if(i-1 >=0){
                    visited[i-1] = 1;
                }
                if(i+1 <size){
                    visited[i+1] = 1;
                }
                count++;
            }
        }
        
      if(count >= n){
        return true;
      }  
      else{
        return false;
      }
    }
};