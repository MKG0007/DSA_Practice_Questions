class Solution {
public:
    void findGroup(vector<int> &arr , set<vector<int>> &ans , vector<int> &group , int index , int target){
        if(index >= arr.size()){
            if(target == 0){
                ans.insert(group);
            }
            return;
        }
            if(arr[index]<=target){
                group.push_back(arr[index]);
                findGroup(arr , ans , group , index+1 , target-arr[index]);
                group.pop_back();
            }
            findGroup(arr , ans , group , index+1 , target);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {

        vector<vector<int>> a;
        vector<int> group;
        sort(arr.begin() , arr.end());
        set<vector<int>> ans;



        findGroup(arr , ans , group , 0 , target);

        for(vector<int> i : ans){
            a.push_back(i);
        }

        return a;

        
    }
};