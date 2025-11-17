class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        unordered_map<int , int > m;

        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i] == 1){
                if(m.find(nums[i]) != m.end()){
                    int num = m[nums[i]];
                    if( (i-num)-1 < k) return false;
                }
                m[nums[i]] = i;
            }

        }
        return true;
    }
};