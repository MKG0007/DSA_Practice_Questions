//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  void merge(vector<int> &arr , int low , int mid , int high){
      int i = low;
      int j = mid+1;
      vector<int> temp;
      while(i<=mid && j<=high){
          if(arr[i]<=arr[j]){
              temp.push_back(arr[i]);
              i++;
          }
          else{
              temp.push_back(arr[j]);
              j++;
          }
      }
      
      while(i<=mid){
          temp.push_back(arr[i]);
          i++;
      }
      
      while(j<=high){
          temp.push_back(arr[j]);
          j++;
      }
      
      for(int i = low ; i<=high ; i++){
          arr[i] = temp[i-low];
      }
      
  }
  
  
  void msort(vector<int> &arr , int low , int high){
      if(low>=high){
          return;
      }
      int mid = (low+high)/2;
      msort(arr , low , mid);
      msort(arr , mid+1 , high);
      
      merge(arr , low , mid , high);
  }
    void mergeSort(vector<int>& arr, int l, int r) {
        msort(arr , l , r);
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
        Solution obj;
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends