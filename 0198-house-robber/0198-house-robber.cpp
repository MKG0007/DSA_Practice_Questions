class Solution {
public:
    int maxMoney(vector<int> &dp , vector<int> & nums , int index){
        if(index == 0) return nums[0];
        if(index <0) return 0;
        if(dp[index] != -1) return dp[index];
        int pick = nums[index] + maxMoney(dp , nums , index-2);
        int notPick = 0 + maxMoney(dp , nums , index-1);

        return dp[index] = max(pick , notPick);

    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() , -1);

        return maxMoney(dp , nums , nums.size()-1);
        
    }
};