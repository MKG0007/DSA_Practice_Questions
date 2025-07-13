class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int size = arr.size();
        unordered_map<int , int> m;
        int len = 0;
        int sum = 0;
        
        for(int i = 0 ; i<size ; i++){
            sum += arr[i];
            if(sum == k){
                len = max(len , i+1);
            }
            int check = sum - k;
            if(m.find(check) != m.end()){
                len = max(len , i-m[check]);
            }
            if(m.find(sum) == m.end()){
                m[sum] = i;
            }
        }
        // code here
        
        return len;
        
    }
};