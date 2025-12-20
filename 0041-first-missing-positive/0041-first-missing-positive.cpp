class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        
        if(arr.size() == 0) return 0;
        if(arr.size() == 1) {if(arr[0] != 1) return 1;}
        int large = INT_MIN;
        int pos = 0;
        for(int i = 0 ; i<arr.size() ; i++){
            if(arr[i] >= 1e6) continue;
            large = max(large , arr[i]);
            if(arr[i]>0) pos++;
            
        }
        if(pos == 0) return 1;
        
        vector<int> ans(large+1 , 0);
        for(int i = 0 ; i<arr.size() ; i++){
            if(arr[i]>0 && arr[i]<=large){
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