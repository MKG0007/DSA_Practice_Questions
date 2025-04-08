class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();

        for (int ops = 0; ops * 3 <= n; ++ops) {
            unordered_set<int> seen;
            bool isDistinct = true;
            for (int i = ops * 3; i < n; ++i) {
                if (seen.count(nums[i])) {
                    isDistinct = false;
                    break;
                }
                seen.insert(nums[i]);
            }

            if (isDistinct) {
                return ops;
            }
        }
        return (n + 2) / 3;
    }
};
