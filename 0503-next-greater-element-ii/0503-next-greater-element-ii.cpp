class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int size = arr.size();
        
        vector<int> ans(size , -1);
        stack<int> st;
        
        for(int i = (2*size)-1 ; i>=0 ; i--){
            while(!st.empty() && arr[st.top()] <= arr[i%size]){
                st.pop();
            }
            
            if(!st.empty()) ans[i%size] = arr[st.top()];
            else ans[i%size] = -1;
            
            st.push(i%size);
        }
        
        return ans;
    }
};