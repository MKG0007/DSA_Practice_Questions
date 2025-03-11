//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  void rrr(vector<int> &arr , int i , int size){
      if(i >= size/2){
          return;
      }
      
      swap(arr[i] , arr[size-i-1]);
      rrr(arr , i+1 ,size);
  }
    void reverseArray(vector<int> &arr) {
        if(arr.size() == 1) return ;
        rrr(arr , 0 , arr.size());
        
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
        ob.reverseArray(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends