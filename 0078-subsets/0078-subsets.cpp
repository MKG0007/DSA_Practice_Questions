class Solution {
public:

    void find(vector<vector<int>> &ans , vector<int> sub , vector<int> &nums ,  int index){
        if(index == nums.size()){
            ans.push_back(sub);
            return ;
        }

        sub.push_back(nums[index]);
        find(ans , sub , nums , index+1);
        sub.pop_back();
        find(ans , sub , nums , index+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        find(ans , sub , nums , 0);
        return ans;
    }
};