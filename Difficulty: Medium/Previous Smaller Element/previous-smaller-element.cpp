class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        stack<int> st;
        int size = arr.size();
        vector<int> ans(size , -1);
        
        
        for(int i = 0 ; i<size ; i++){
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top();
            
            st.push(arr[i]);
        }
        
        return ans;
        
    }
};