class Solution {
public:
    static int largestPerimeter(vector<int>& nums) {
        const int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=n-1; i>1; i--){
            if (nums[i]<nums[i-1]+nums[i-2]) 
            return nums[i]+nums[i-1]+nums[i-2];
        }
        return 0;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();