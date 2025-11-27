class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> minPref(k, LLONG_MAX); 

        long long prefix = 0;
        long long ans = LLONG_MIN;

        minPref[0] = 0; // before starting, prefix = 0 at remainder 0

        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            int r = (i + 1) % k;

            if (minPref[r] != LLONG_MAX) {
                ans = max(ans, prefix - minPref[r]);
            }

            minPref[r] = min(minPref[r], prefix);
        }

        return ans;
    }
};
