class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return nums[0];
        sort(nums.begin() , nums.end());

        int freq = 1;
        int ans = nums[0];
        for(int i = 1 ; i<size ; i++){
            if(ans == nums[i]){
                freq++;
            }
            else{
                freq = 1;
                ans = nums[i];
            }
            if(freq>size/2){
                return ans;
            }
        }
    }
};