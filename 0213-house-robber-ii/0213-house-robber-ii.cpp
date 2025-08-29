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
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        // if(nums.size() == 2) return 0;

        vector<int> temp1 , temp2;

        for(int i = 0 ; i<nums.size() ; i++){
            if(i != nums.size()-1){
                temp1.push_back(nums[i]);
            }
            if(i != 0){
                temp2.push_back(nums[i]);
            }

        }
        vector<int> dp1(temp1.size() , -1);
        vector<int> dp2(temp2.size() , -1);

        int ans1 = maxMoney(dp1 , temp1 , temp1.size()-1);
        int ans2 = maxMoney(dp2 , temp2 , temp2.size()-1);

        return max(ans1 , ans2);
        
    }
};