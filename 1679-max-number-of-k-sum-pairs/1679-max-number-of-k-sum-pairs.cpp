class Solution {
public:
    int maxOperations(vector<int>& nums, int target) {
        int size = nums.size();
        sort(nums.begin() , nums.end());
        int s = 0;
        int e = size-1;
        int count = 0;
        while(s<e){
            int sum = nums[s] + nums[e];
            if(sum == target){
                count++;
                s++;
                e--;
            }
            else if(sum>target){
                e--;
            }
            else{
                s++;
            }
        }
        return count;
    }
};