//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    void firstLast(vector<int> &arr , int x , vector<int> &ans , int i){
        if(i>=arr.size() || i<0){
            return;
        }
        
        if(arr[i] == x){
            ans[1] = i;
        }
        firstLast(arr , x , ans , i+1);
        // firstLast(arr , x , ans , i-1 , index);
        if(arr[i] == x){
            ans[0] = i;
        }
        
    }
    vector<int> find(vector<int>& arr, int x) {
        vector<int> ans(2 , -1);
        firstLast(arr , x , ans , 0);
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
        int x;
        cin >> x;
        cin.ignore();
        vector<int> ans;
        Solution ob;
        ans = ob.find(arr, x);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends