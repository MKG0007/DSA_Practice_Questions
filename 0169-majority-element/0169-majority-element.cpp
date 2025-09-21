class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();

        int freq = 0;
        int number = 0;

        for(int i = 0 ; i<size ; i++){
            if(freq == 0) number = nums[i], freq = 1;
            else if(nums[i] == number) freq++;
            else freq--;
        }

        return number;
        
    }
};