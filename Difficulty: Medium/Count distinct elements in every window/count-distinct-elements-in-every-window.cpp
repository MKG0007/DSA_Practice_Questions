//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        unordered_map<int , int> m;
        
        vector<int> ans;
        
        for(int i = 0 ; i<k ; i++){
            m[arr[i]]++;
        }
        
        ans.push_back(m.size());
        
        for(int i = k ; i<arr.size() ; i++){
            
            int add = arr[i];
            int sub = arr[i-k];
            
            m[add]++;
            
            if(--m[sub] == 0){
                m.erase(sub);
                
            }
            
            ans.push_back(m.size());
            
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends