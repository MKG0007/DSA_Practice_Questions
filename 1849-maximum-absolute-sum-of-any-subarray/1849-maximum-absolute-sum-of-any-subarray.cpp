class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0;
        int crr = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            crr += nums[i];
            if(crr<0){
                crr = 0;
            }
            maxSum = max(maxSum , crr);
        }
        crr = 0;
        int minSum = 0;
        for(int i = 0  ;i<nums.size() ; i++){
            crr += nums[i];
            if(crr>0){
                crr = 0;
            }
            minSum = min(minSum , crr);
        }
        minSum = -minSum;


        return max(minSum , maxSum);
        
    }
};