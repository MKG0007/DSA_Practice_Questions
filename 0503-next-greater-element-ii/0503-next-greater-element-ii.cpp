class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size , 0);
        stack<int> st;

        for(int i = (2*size-1) ; i>=0 ; i--){
            while(!st.empty() && nums[st.top()]<=nums[i%size]){
                st.pop();
            }
            if(st.empty()){
                ans[i%size] = -1;
            }
            else{
                ans[i%size] = nums[st.top()];
            }

            st.push(i%size);
        }
        return ans;
    }
};