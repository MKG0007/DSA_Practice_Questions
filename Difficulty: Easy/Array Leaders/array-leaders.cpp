

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int size = arr.size();
        vector<int> ans;
        int crr = INT_MIN;
        for(int i = size-1 ; i>=0 ; i--){
            if(arr[i]>=crr){
                ans.push_back(arr[i]);
            }
            
            crr = max(crr , arr[i]);
        }
        
        reverse(ans.begin() , ans.end());
        return ans;
    }
};