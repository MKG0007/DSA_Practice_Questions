class Solution {
public:
    int helper(vector<int>& nums, int target, int sum, int idx) {
        if (idx == nums.size()) {
            return target == sum ? 1 : 0;
        }

        int add = helper(nums, target, sum + nums[idx], idx + 1);
        int subtract = helper(nums, target, sum - nums[idx], idx + 1);

        return add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums, target, 0, 0);
    }
};