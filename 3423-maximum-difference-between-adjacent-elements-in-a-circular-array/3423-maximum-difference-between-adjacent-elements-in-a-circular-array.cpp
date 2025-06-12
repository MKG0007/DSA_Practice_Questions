class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {


        int size = nums.size();
        if(size == 1) return nums[0];
        int maxdiff = INT_MIN;
        maxdiff = max(maxdiff , abs(nums[0] - nums[size-1]));
        int crr = abs(nums[0] - nums[size-1]);
        for(int i = 1 ; i<size ; i++){
            crr = abs(nums[i-1] - nums[i]);
            maxdiff = max(maxdiff , crr);
        }
        return maxdiff;
    }
};