// User function template for C++

class Solution {
  public:
  bool isvalid(vector<int>&arr , int painters , int maxtime){
      int time = 0;
      int pp = 1;
      for(int i  = 0 ; i<arr.size() ; i++){
        //   if(maxtime < arr[i]) return false;
          if(time + arr[i] <= maxtime){
              time += arr[i];
          }
          else{
              pp++;
              time = arr[i];
          }
          
      }
      if(pp <= painters) return true;
      return false;
  }
    int minTime(vector<int>& arr, int k) {
        int size = arr.size();
        int start = INT_MIN;
        int end = 0;
        
        for(int i = 0 ; i<size ; i++){
            start = max(start , arr[i]);
            end += arr[i];
        }
        int mintime = INT_MAX;
        while(start<=end){
            int mid = start + (end - start)/2;
            
            if(isvalid(arr , k , mid)){
                mintime = min(mintime , mid);
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return mintime;
    }
};