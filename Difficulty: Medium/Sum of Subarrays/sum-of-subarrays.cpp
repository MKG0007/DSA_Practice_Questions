class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        int sum  = 0;
        for(int i = 0 ; i<arr.size() ; i++){
            sum += arr[i]*(i+1)*(arr.size()-i);
        }
        return sum;
    }
};