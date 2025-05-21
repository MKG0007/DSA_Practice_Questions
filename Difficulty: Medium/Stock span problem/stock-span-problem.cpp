class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int size = arr.size();
        vector<int> ans;
        
        if(size == 0){return ans;}
        
        stack<int> st;
        
        for(int i = 0 ; i<size ; i++){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            if(st.empty()){ans.push_back(i+1);}
            else{
                ans.push_back(i-st.top());
            }
            
            st.push(i);
        }
        
        return ans;
    }
};