class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        int suffix = 1;
        vector<int> ans(size , 1);
        for(int i = 1 ; i<size ; i++){
            ans[i] *= ans[i-1] * nums[i-1]; 
        }    
        for(int i = size-2 ; i>=0 ; i--){
            suffix *= nums[i+1];
            ans[i] *= suffix;

        }  

        return ans;  
    }
};