class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        if(arr.size() == 0) return 0;
        int large = INT_MIN;
        int pos = 0;
        for(int i = 0 ; i<arr.size() ; i++){
            large = max(large , arr[i]);
            if(arr[i]>0) pos++;
            
        }
        if(pos == 0) return 1;
        
        vector<int> ans(large+1 , 0);
        for(int i = 0 ; i<arr.size() ; i++){
            if(arr[i]>0){
            ans[arr[i]]++;
            }
        }
        int num = 0;
        for(int i = 1 ; i<ans.size() ; i++){
            if(ans[i] == 0){
                num = i;
                break;
            }
        }
        
        if(num == 0) return large+1;
        
        return num;
    }
};