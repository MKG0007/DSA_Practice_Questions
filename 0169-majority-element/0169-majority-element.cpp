class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();

        int freq = 0;
        int ans = 0;

        for(int i = 0 ; i<size ; i++){
            if(freq == 0){
                ans = nums[i];
            }
            if(ans == nums[i]){
                freq++;
            }
            else{
                freq--;
            }
        }
     return ans;   
    }
};