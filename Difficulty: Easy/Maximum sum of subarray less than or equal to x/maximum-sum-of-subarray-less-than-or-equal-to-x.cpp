class Solution {
  public:
    long long findMaxSubarraySum(vector<int>& arr, long long x) {
        int size = arr.size();
        
        int left = 0;
        int right = 0;
        int sum = 0;
        int ans = INT_MIN;
        
        while(right < size){
            sum += arr[right];
            right++;
            while(left <= right && sum>x){
                sum -= arr[left];
                left++;
            }
            
            ans = max(ans , sum);
        }
        
        return ans;
    }
};
