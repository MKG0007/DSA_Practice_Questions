class Solution {
public:
    void totalSub(vector<vector<int>> &ans , vector<int> sub , vector<int> &arr , int target , int index){
        if(index == arr.size()){
            if(target == 0) ans.push_back(sub);
            return ;
        }
        if(arr[index]<=target){
        sub.push_back(arr[index]);
        target -= arr[index];
        totalSub(ans , sub , arr , target , index);
        target += arr[index];
        sub.pop_back();
        }

        // target += arr[index];
        totalSub(ans , sub , arr , target , index+1);



    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sub;

        totalSub(ans , sub , candidates , target , 0);

        return ans;
        
    }
};