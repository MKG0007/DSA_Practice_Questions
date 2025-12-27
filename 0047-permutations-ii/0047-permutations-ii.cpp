class Solution {
public:
    set<vector<int>> ans;
    void backtrack(vector<int>& nums, vector<int>& perm, vector<int>& used) {
        if(perm.size()==nums.size()) {
            ans.insert(perm);
            return;
        }
        for(int i=0;i<nums.size();i++) {
            if(used[i]) continue;
            used[i]=true;
            perm.push_back(nums[i]);
            
            backtrack(nums,perm,used);
            perm.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        int n=nums.size();
        vector<int> perm;
        vector<int> used(n,false);

        backtrack(nums,perm,used);
        vector<vector<int>> v(ans.begin(),ans.end());
        return v;
    }
};