//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        int start = 0 ;
        int end = arr.size()-1;
        vector<int> ans(2 , -1);
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(arr[mid] == x){
                ans[0] = mid;
                end = mid-1;
            }
            else if(arr[mid]>x){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        
        start = 0;
        end = arr.size()-1;
        
            while(start<=end){
            int mid = start + (end-start)/2;
            
            if(arr[mid] == x){
                ans[1] = mid;
                start = mid+1;
            }
            else if(arr[mid]>x){
                end = mid-1;
            }
            else{
                start = mid+1;
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