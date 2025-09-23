class Solution {
  public:
    int longestSubarray(vector<int>& nums, int t) {
        // code here
        int size = nums.size();
        unordered_map<int , int> m;
        int sum = 0;
        int maxi = 0;
        for(int i = 0 ; i<size ; i++){
            sum += nums[i];
            if(sum == t){
                maxi = max(maxi , i+1);
            }
            int rem = sum - t;
            if(m.find(rem) != m.end()) maxi = max(maxi , i-m[rem]);
            
            if(m.find(sum) == m.end()) m[sum] = i;
        }
        
        
        
        
        return maxi;
    }
};