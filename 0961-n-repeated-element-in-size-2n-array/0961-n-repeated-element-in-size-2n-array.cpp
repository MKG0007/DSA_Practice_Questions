class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> m;
        for(int i = 0; i<nums.size() ; i++){
            if(m.find(nums[i]) != m.end()) return nums[i];

            m.insert(nums[i]);
        }

        return -1;
        
    }
};