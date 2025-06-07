// User function template for C++

class Solution {
  public:
    int maxProduct(vector<int> arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    
    int option1 = arr[n-1] * arr[n-2] * arr[n-3];
    int option2 = arr[0] * arr[1] * arr[n-1];

    return max(option1, option2);
    }
};