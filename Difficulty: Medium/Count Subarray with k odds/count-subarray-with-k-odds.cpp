class Solution {
  public:
  int helper(vector<int> &arr , int k){
        int size = arr.size();
        
        int count = 0;
        int left = 0;
        int oddCount = 0;
        for(int i = 0 ; i<size ; i++){
            if(arr[i]%2 != 0) oddCount++;
            
            while(oddCount>k){
                if(arr[left]%2 != 0) oddCount--;
                left++;
            }
            
            if(oddCount <= k) count += i-left +1;
        }
        
        return count;
  }
    int countSubarrays(vector<int>& arr, int k) {
        
        return helper(arr , k) - helper(arr , k-1);
        
    }
};