class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        // code here
        int n = arr.size();
        for(int i = 0; i < n;i++)
        {
            arr.push_back(arr[i]);
        }
        
        vector<int> temp(2*n,-1);
        stack<int> st;
        for(int i = 2*n-1; i>=0;i--)
        {
            
            while(!st.empty() && st.top()<= arr[i])
            st.pop();
            
            
            if(!st.empty() && st.top()>arr[i])
            temp[i] = st.top();
            
            st.push(arr[i]);
        }
        return vector<int>(temp.begin(), temp.begin() + n);
    }
};