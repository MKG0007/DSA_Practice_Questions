// User function template for C++
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        int size = arr.size();
        unordered_set<int> sm;
        
        for(int i = 0 ; i<size ; i++){ 
            int num = target-arr[i];
            if(sm.find(num) != sm.end()){
                return true;
            }
            
            sm.insert(arr[i]);
            
        }
        return false;
    }
};