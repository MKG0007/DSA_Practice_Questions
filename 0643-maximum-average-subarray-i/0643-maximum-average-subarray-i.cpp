class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        double crrAvg = 0;
        double ans = INT_MIN;

        if(nums.size() == 1) return nums[0];

        for(int i = 0 ; i<k ; i++){
            crrAvg += (double)nums[i];
        }
        ans = max(ans , crrAvg/k);

        for(int i = k ; i<nums.size() ; i++){
            double add = nums[i];
            double sub = nums[i-k];
            crrAvg = crrAvg + add - sub;
            ans = max(ans , crrAvg/k);
        }

        return ans;
        
    }
};