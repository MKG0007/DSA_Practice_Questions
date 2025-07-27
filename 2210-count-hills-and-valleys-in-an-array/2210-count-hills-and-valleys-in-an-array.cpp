class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        int size = nums.size();
        if(size == 0) return 0;
        if(size == 1) return 1;

        for(int i = 1 ; i<size-1 ; i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            int left = i-1;
            int right = i+1;
            while(left>=0 && nums[left] == nums[i]){
                left--;
            }

            while(right<nums.size() && nums[right] == nums[i]){
                right++;
            }
            if(left >= 0 && right <size){
                if(nums[right] != nums[i] && nums[left] != nums[i]){
                if(nums[left] < nums[i] && nums[right] < nums[i]) count++;
                else if(nums[left] > nums[i] && nums[right] > nums[i]) count++;
                }
            }
        }
        return count;
    }
};