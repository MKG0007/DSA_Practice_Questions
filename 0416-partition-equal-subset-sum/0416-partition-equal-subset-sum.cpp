class Solution {
public:
    bool check(vector<int> &nums , vector<vector<int>> &dp , int target , int index){
        if(target == 0) return true;
        if(index == 0) return target == nums[0];
        if(dp[index][target] != -1) return dp[index][target];

        int pick = false;
        if(nums[index]<target) pick = check(nums , dp , target-nums[index] , index-1);

        int notpick = check(nums , dp , target , index-1);

        return dp[index][target] = pick || notpick;
    }
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        int totalSum = 0;
        for(int i = 0 ; i<size ; i++) totalSum += nums[i];

        if(totalSum%2 != 0) return false;

        int t = totalSum/2;
        vector<vector<int>> dp(size , vector<int>(t+1 , -1));

        if(check(nums , dp , t , size-1)) return true;

        return false;
        
    }
};