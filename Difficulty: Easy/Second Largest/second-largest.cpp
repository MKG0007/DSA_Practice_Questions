//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        
        if(arr.size() == 1) return arr[0];
        vector<int> visited(arr.size() , 0);
        
        
        int maxEle = INT_MIN;
        
        for(int i = 0 ; i<arr.size() ; i++){
            maxEle = max(maxEle , arr[i]);
        }
        
        for(int i = 0 ; i<arr.size() ; i++){
            if(maxEle == arr[i]){
                visited[i] = 1;
            }
        }
        
        
        int ans = -1;
        for(int i = 0 ; i<arr.size() ; i++){
            if(!visited[i]){
                ans = max(ans , arr[i]);
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends