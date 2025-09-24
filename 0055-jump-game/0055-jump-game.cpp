class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int minIndex = 0;
        for(int i = 0 ; i<size ; i++){
            if(i>minIndex) return false;

            minIndex = max(minIndex , i+nums[i]);
        }

        return true;

    }
};