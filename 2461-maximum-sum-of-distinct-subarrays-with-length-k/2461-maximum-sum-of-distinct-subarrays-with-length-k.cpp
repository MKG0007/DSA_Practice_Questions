class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> cnt; // frequency map for current window
        long long sum = 0;
        long long best = 0;        // default 0 when no valid window found
        int l = 0;

        for (int r = 0; r < n; ++r) {
            sum += nums[r];
            cnt[nums[r]]++;

            // If duplicate present, shrink from left until duplicates removed
            while (cnt[nums[r]] > 1) {
                cnt[nums[l]]--;
                sum -= nums[l];
                l++;
            }

            // If window has size k and all elements are distinct, consider it
            if (r - l + 1 == k) {
                best = max(best, sum);

                // Move left to slide window by one for next iteration:
                cnt[nums[l]]--;
                sum -= nums[l];
                l++;
            }
        }

        return best;
        
    }
};