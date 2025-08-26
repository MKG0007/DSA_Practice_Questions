// User function Template for C++

class Solution {

  public:
  void uiqueSubset(vector<vector<int>> &ans , vector<int> sub , vector<int> &nums , int index){
      
      ans.push_back(sub);
      
      for(int i = index ; i<nums.size() ; i++){
          if(i != index && nums[i] == nums[i-1]) continue;
          sub.push_back(nums[i]);
          uiqueSubset(ans , sub , nums , i+1);
          sub.pop_back();
      }
      
  }
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        // Write your code here
        sort(nums.begin() , nums.end());
        
        vector<vector<int>> ans;
        vector<int> sub;
        
        uiqueSubset(ans , sub , nums , 0);
        
        return ans;
        
    }
};