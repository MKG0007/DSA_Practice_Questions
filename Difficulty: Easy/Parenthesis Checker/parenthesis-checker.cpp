class Solution {
  public:
    bool isBalanced(string& s) {
        
        int size = s.length();
        stack<char> st;
        
        for(int i = 0 ; i<size ; i++){
            if(s[i] == '[' || s[i] == '(' || s[i] == '{'){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    
                    char ch = st.top();
                    if((ch == '[' && s[i] == ']') || (ch == '{' && s[i] == '}') || (ch == '(' && s[i] == ')')){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
            
            
        }
            if(st.size() == 0) return true;
            return false;
    }
};