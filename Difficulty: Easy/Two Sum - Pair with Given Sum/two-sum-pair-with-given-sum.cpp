class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        int size = arr.size();
        
        unordered_set<int> s;
        
        for(int i = 0 ; i<size ; i++){
            int num1 = arr[i];
            int num2 = target-arr[i];
            
            if(s.find(num2) != s.end()){
                return true;
            }
            s.insert(arr[i]);
        }
        
        return false;
    }
};