class Solution {
public:

    void totalSubset(vector<int> &nums , vector<int> subset , vector<vector<int>> &ans , int index , int size){
        if(index == size){
            ans.push_back(subset);
            return ;
        }
        subset.push_back(nums[index]);
        totalSubset(nums , subset , ans , index+1 , size);
        subset.pop_back();
        totalSubset(nums , subset , ans , index+1 , size);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans ;
        vector<int> subset;
        int size = nums.size();

        totalSubset(nums , subset ,ans , 0 , size);

        return ans;
        
    }
};