class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int size = arr.size();
        vector<int> ans(size , -1);
        
        if(size == 0){
            return ans;
        }
        
        stack<int> st;
        for(int i = size-1 ; i>=0 ; i--){
            while(!st.empty() && st.top() <= arr[i]){
                st.pop();
            }
            if(!st.empty() && st.top()>arr[i]){
                ans[i] = st.top();
            }
            
            
            st.push(arr[i]);
        }
        
        return ans;
        
    }
};