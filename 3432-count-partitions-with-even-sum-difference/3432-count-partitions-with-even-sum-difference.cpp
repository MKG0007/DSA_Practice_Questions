class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int  sum=accumulate(nums.begin(),nums.end(),0);
                if(sum%2!=0) return 0;
        return n-1;

    }
};