

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        int size = arr.size();
        // Code here
        vector<int> ans;
        if(size == 0) return ans;
        if(size == 1) return {arr[0]};
        
        int maxi = INT_MIN;
        for(int i = size-1 ; i>=0 ; i--){
            if(maxi<=arr[i]){
                ans.push_back(arr[i]);
            }
            maxi = max(maxi , arr[i]);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};