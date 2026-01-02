class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int count = 0;
        int num = nums[0];
        for(int i = 0; i<nums.size() ; i++){
            if(num == nums[i]) count++;
            else if(num != nums[i]) count = 1, num = nums[i];

            if(count >1) return num;
        }

        return -1;
        
    }
};