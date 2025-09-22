class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {

        unordered_map<int , int> m;
        int mfreq = 0;
        for(int i = 0 ; i<nums.size() ; i++){

            if(m.find(nums[i]) != m.end()){
                m[nums[i]]++;
            }
            else{
                m[nums[i]] = 1;
            }

            mfreq = max(mfreq , m[nums[i]]);

            
        }
        int count = 0;
        for(auto val : m){
            if(val.second == mfreq){
                count += val.second;
            }
        }

        return count;
        
    }
};