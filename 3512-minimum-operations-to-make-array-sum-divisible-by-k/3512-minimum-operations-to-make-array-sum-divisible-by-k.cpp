class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int size = nums.size();
        long long sum = 0;

        for(int i = 0 ; i<size ; i++){
            sum += nums[i];
        }

        int ans = sum%k;

        return ans;
        
    }
};