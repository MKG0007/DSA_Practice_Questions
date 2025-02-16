class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        unordered_map<int , int> m;

        for(int i = 0 ; i < size ; i++){
            int n1 = nums[i];
            int n2 = target - nums[i];

            if(m.find(n2) != m.end()){
                return {i , m[n2]};
            }
            m[n1] = i;
    }
 
    return {0 , 0};
    }
};