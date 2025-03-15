#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canRob(nums, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

private:
    bool canRob(vector<int>& nums, int k, int capability) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= capability) {
                count++;
                i++;
            }
            if (count >= k) return true;
        }
        return false;
    }
};