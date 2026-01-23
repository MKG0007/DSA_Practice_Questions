class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        int size = arr.size();
        if(size == 0) return 0;
        if(size == 1) return 1;
        vector<int> cal(size , 1);
        stack<int> st;
        for(int i = size -1 ; i>=0 ; i--){
            
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            if( (size-1) != i && st.empty()){
                cal[i] += (size-1) - i;
            }
            else if(!st.empty()){
                cal[i] += st.top()-i-1;
            }
            
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i = 0 ; i<size ; i++){
            
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            
            if(i != 0 && st.empty()){
                cal[i] += i;
            }
            else if(!st.empty()){
                cal[i] += i - st.top()-1;
            }
            
            st.push(i);
            
        }
        
        
        int m = INT_MIN;
        for(int i = 0 ; i<size ; i++){
            m = max(m , cal[i]);
        }
        
        return m;
        
    }
};