//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        int crrsum = 0;
        int ans = 0;
        for(int i = 0 ; i<k ; i++){
            crrsum += arr[i];
        }
        ans = crrsum;
        
        for(int i = k ; i<arr.size() ; i++){
            int sub = arr[i-k];
            int add = arr[i];
            crrsum  = crrsum +add - sub;
            ans = max(ans , crrsum);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        int ans = ob.maximumSumSubarray(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends