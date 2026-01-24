
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int maxP=0;
        for(int i=0; i<n/2; i++)
            maxP=max(maxP, nums[i]+nums[n-1-i]);
        return maxP;
    }
};