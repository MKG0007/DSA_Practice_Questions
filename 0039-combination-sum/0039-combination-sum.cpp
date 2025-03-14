class Solution {
public:

    void findCombinations(vector<int> &arr , vector<vector<int>> &ans , vector<int> &temp , int index , int target){
        if(target<=0 || index >= arr.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }

        if(arr[index]<=target){
            temp.push_back(arr[index]);
            findCombinations(arr , ans , temp , index , target-arr[index]);
            temp.pop_back();
        }
            findCombinations(arr , ans , temp , index+1 , target);

    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int> combination;
        vector<vector<int>> ans;

        findCombinations(arr , ans , combination , 0 , target);
        return ans;
        
    }
};