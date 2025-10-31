class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int , int> m;
        vector<int> ans;
        for(int i = 0 ; i<nums.size() ; i++){
            if(m.find(nums[i]) != m.end()){
                if(m[nums[i]] == 1){
                    ans.push_back(nums[i]);
                }
            }
            m[nums[i]]++;

        }

        return ans;
        
    }
};