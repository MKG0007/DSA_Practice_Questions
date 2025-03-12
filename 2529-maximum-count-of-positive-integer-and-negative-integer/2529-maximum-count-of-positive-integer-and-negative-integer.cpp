class Solution {
public:
    int maximumCount(vector<int>& nums) {

        int countNegative = 0;
        int countPositive = 0;
        int check = 0;

        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i]>0){
                countPositive++;
                check = nums[i];
            }
            if(nums[i]<0){
                countNegative++;
                check = nums[i];
            }
        }

        return max(countNegative , countPositive);
        
    }
};