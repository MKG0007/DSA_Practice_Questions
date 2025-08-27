

class Solution {
public:
    void findGroup(vector<int> &arr , vector<vector<int>> &ans , vector<int> &group , int index , int target){
        if(target == 0){
            ans.push_back(group);
            return;
        }
        for(int i = index ; i<arr.size() ; i++){
            if(i>index && arr[i] == arr[i-1]){
                continue;
            }
            if(arr[i]>target) break;
            group.push_back(arr[i]);
            findGroup(arr , ans , group , i+1 , target-arr[i]);
            group.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        sort(arr.begin() , arr.end());

        vector<int> group;//to store combination

        findGroup(arr , ans , group , 0 , target);

        return ans;
    }
};