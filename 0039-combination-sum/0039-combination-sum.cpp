class Solution {
public:
    void findGroup(vector<int> &arr , vector<vector<int>> &ans , vector<int> &group , int index , int target){
        if(index >= arr.size()){
            if(target == 0){
                ans.push_back(group);
            }
            return;
        }
        if(target<0) return;
        
        group.push_back(arr[index]);
        findGroup(arr , ans , group , index , target-arr[index]);

        group.pop_back();
        findGroup(arr , ans , group , index+1 , target);

        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> group;
        findGroup(candidates , ans , group , 0 , target);
        return ans;
    }
};