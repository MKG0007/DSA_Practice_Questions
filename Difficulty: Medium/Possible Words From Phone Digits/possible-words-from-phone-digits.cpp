class Solution {
  public:
void solve(int i, int n, vector<int>&arr, string temp, vector<string>&ans, vector<string>keys) {
    
        if(i==n) {
            ans.push_back(temp);
            return;
        }
        
         
        if (keys[arr[i]].empty()) {
            solve(i + 1, n, arr, temp, ans, keys);
            return;
        }
        
        for(int j=0; j<keys[arr[i]].size(); j++) {
            solve(i+1, n, arr, temp+keys[arr[i]][j], ans, keys);
        }
    }
    
    vector<string> possibleWords(vector<int> &arr) {
    
        vector<string>keys = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>ans;
        solve(0, arr.size(), arr, "", ans, keys);
        return ans;
    }


};