class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long mx = 0;     
        long long mx2 = -1e6;  
        long long ans = 0;     

        for (int i = 0; i < nums.size(); ++i) {
            ans = max(ans, mx2 * nums[i]);    
            mx2 = max(mx2, mx - nums[i]);     
            mx = max(mx, (long long)nums[i]);  
        }
        return ans; 
    }
};