class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) {
        int size = arr.size();
        vector<int> ans(size , 0);
        if(size == 0) return ans;
        stack<int> st;
        
        for(int i = 0 ; i<size ; i++){
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }
            else{
               ans[i] = st.top(); 
            }
            st.push(arr[i]);
        }
        
        return ans;
        
        
    }
};