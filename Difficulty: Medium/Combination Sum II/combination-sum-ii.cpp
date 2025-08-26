// User function template for C++

class Solution {
  public:
    // Function to find all combinations of elements
    // in array arr that sum to target.
    
    void totalUnique(vector<vector<int>> &ans , vector<int> &arr , vector<int> sub , int target , int index){
        if(target == 0){
            ans.push_back(sub);
            return;
        }
        
        for(int i = index ; i<arr.size() ; i++){
            if(i>index && arr[i] == arr[i-1]){
                continue;
            }
            if(arr[i]>target){
                break;
            }
            sub.push_back(arr[i]);
            totalUnique(ans , arr , sub , target-arr[i] , i+1);
            sub.pop_back();
        }
    }
    vector<vector<int>> uniqueCombinations(vector<int> &arr, int target) {
        sort(arr.begin() , arr.end());
        vector<vector<int>> ans;
        vector<int> sub;
        
        totalUnique(ans , arr , sub, target , 0);
        
        return ans;
        
    }
};