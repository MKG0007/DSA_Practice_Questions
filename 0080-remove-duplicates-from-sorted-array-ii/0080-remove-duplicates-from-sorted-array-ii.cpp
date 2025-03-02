class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        unordered_map<int , int> m;

        for(int i = 0 ; i<nums.size() ; i++){
            m[nums[i]]++;
        }
        int count = 1;
        for(int i = 1 ; i<nums.size() ; i++){
            if(nums[i-1] == nums[i]){
                count++;
            }
            else{
                count = 1;
            }

            if(count>2){
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        return nums.size();
    }
};