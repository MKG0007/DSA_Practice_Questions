class Solution {
public:
    int maximumCount(vector<int>& nums) {
        if(nums.size() == 1){
            if(nums[0] == 0){
                return 0;
            }
            return 1;
        }

        int countNegative = 0;
        int countPositive = 0;
        int check = 0;
        int start = 0;
        int end = nums.size()-1;
        while(start<=end){
            if(nums[start]>0){
                countPositive++;
            }
            if(nums[end] >0 && end != start){
                countPositive++;
            }
            if(nums[start]<0){
                countNegative++;
            }
            if(nums[end]<0 && end != start){
                countNegative++;
            }
            start++;
            end--;
        }

        return max(countNegative , countPositive);
        
    }
};