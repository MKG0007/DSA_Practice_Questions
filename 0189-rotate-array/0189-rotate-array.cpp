class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k%size;

        reverse(nums.begin() , nums.begin()+(size - k));
        reverse(nums.begin()+(size -k) , nums.end());
        reverse(nums.begin() , nums.end());

        // return nums;
    }
};