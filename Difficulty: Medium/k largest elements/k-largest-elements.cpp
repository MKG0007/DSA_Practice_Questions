class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        int size = arr.size()-1;
        sort(arr.begin() , arr.end());
        vector<int> ans;
        for(int i = size ; i>size-k ; i--){
            ans.push_back(arr[i]);
            
        }
        
        return ans;
    }
};