class Solution {
public:
    int subarraySum(vector<int>& nums, int t) {
        int size = nums.size();
        unordered_map<int , int> m;
        int sum = 0;
        int maxi = 0;
        for(int i = 0 ; i<size ; i++){
            sum += nums[i];
            if(sum == t){
                maxi++;
            }
            int rem = sum - t;
            if(m.find(rem) != m.end()) maxi += m[rem];
            
            m[sum]++;
        }
        
        
        
        
        return maxi;
        
    }
};