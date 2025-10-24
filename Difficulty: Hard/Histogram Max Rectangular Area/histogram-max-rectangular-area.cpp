class Solution {
  public:
  
  void leftsmall(vector<int> & arr , vector<int> & left , int size){
      stack<int> st;
      for(int i = 0 ; i<size ; i++){
          while(!st.empty() && arr[st.top()]>=arr[i]){
              st.pop();
          }
          
          if(!st.empty()) left[i] = st.top();
          else left[i] = -1;
          
          st.push(i);
      }
      
  }
  void rightsmall(vector<int> & arr , vector<int> & right , int size){
      stack<int> st;
      for(int i = size-1 ; i>=0 ; i--){
          while(!st.empty() && arr[st.top()]>=arr[i]){
              st.pop();
          }
          
          if(!st.empty()) right[i] = st.top();
          else right[i] = size;
          
          st.push(i);
      }
  }
    int getMaxArea(vector<int> &arr) {
        if(arr.size() == 0) return 0;
        if(arr.size() == 1) return arr[0];
        int size = arr.size();
        vector<int> left(size , -1);
        vector<int> right(size , -1);
        
        rightsmall(arr , right , size);
        leftsmall(arr , left , size);
        
        int ans = 0;
        
        for(int i = 0 ; i<size ; i++){

            int crr = arr[i] * (right[i]-left[i]-1);
            
            ans = max(ans , crr);
        }
        
        return ans;
        
    }
};
