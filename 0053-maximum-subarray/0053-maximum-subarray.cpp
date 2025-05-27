class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        // if(size == 1) return nums[0];

        int maxSum = INT_MIN;
        int crrSum = 0;

        for(int i = 0 ; i<size ; i++){
            crrSum += nums[i];

            maxSum = max(maxSum , crrSum);
            if(crrSum<0){
                crrSum = 0;
            }
        }

        return maxSum;
        
    }
};