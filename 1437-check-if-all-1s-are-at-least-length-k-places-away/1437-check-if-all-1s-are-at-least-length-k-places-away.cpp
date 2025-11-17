class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev = -1;

        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i] == 1){
                int ch = i-prev-1;
                if(prev != -1 && ch < k){
                    return false;
                }
                prev = i;
            }

        }
        return true;
    }
};