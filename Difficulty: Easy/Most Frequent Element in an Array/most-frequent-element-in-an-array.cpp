class Solution {
  public:
    int mostFreqEle(vector<int>& nums) {
        // code here
        unordered_map<int , int> m;
        int mfreq = INT_MIN;
        for(int i = 0 ; i<nums.size() ; i++){
            m[nums[i]]++;
            mfreq = max(mfreq , m[nums[i]]);
             }
        int ans = INT_MIN;
        for(auto ele : m){
            if(ele.second == mfreq){
                ans = max(ans , ele.first);
            }

        }

        return ans;
    }
};