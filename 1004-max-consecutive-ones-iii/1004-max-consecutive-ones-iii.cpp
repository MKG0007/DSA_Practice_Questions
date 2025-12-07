class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int size = nums.size();
        int left = 0, zero = 0, count = 0;
        
        for(int right = 0; right < size; right++){
            if(nums[right] == 0) zero++;

            while(zero > k){
                if(nums[left] == 0) zero--;
                left++;
            }
            count = max(count, right - left + 1);
        }

        return count;
    }
};
