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
        dp[0] = nums[0];

        for(int i = 1 ; i<nums.size() ; i++){
            int pick = nums[i];
            if(i-2>=0){
                pick += dp[i-2];
            }
            int notpick = 0 + dp[i-1];
            dp[i] = max(pick , notpick);

        }

        return dp[nums.size()-1];
        
    }
};