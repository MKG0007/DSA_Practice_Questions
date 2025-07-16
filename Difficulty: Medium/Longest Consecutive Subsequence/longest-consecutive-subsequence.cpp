class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    bool search(vector<int> &arr , int target){
        int size = arr.size();
        for(int i = 0 ; i<size ; i++){
            if(target == arr[i]){
                return true;
            }
        }
        return false;
    }
    int longestConsecutive(vector<int>& arr) {
        int size = arr.size();
        int ans = INT_MIN;
        for(int i = 0; i<size ; i++){
            
            int num = arr[i]+1;
            int count = 1;
            while(search(arr , num)){
                count++;
                num++;
            }
            ans = max(ans , count);
        }
        
        return ans;
        
    }
};