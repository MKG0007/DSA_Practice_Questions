class Solution {

  public:
    int minDifference(vector<int>& nums) {
        int size = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<bool>> dp(size, vector<bool>(totalSum + 1, false));

        // Base cases
        for (int i = 0; i < size; i++) dp[i][0] = true;
        dp[0][nums[0]] = true;

        // Fill DP table
        for (int i = 1; i < size; i++) {
            for (int j = 1; j <= totalSum; j++) {
                bool notpick = dp[i-1][j];
                bool pick = false;
                if (nums[i] <= j) pick = dp[i-1][j - nums[i]];

                dp[i][j] = pick || notpick;
            }
        }

        // Find minimum difference
        int ans = totalSum;
        for (int s1 = 0; s1 <= totalSum / 2; s1++) {
            if (dp[size - 1][s1]) {
                int s2 = totalSum - s1;
                ans = min(ans, abs(s2 - s1));
            }
        }

        return ans;
    }
};
