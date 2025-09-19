class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        int len = s.length();
        stack<char> st;
        int count = 0;
        for(int i = 0 ; i<len ; i++){
            if(s[i] == '[' || s[i] == '{' || s[i] == '(') st.push(s[i]);
            
            else{
                if(!st.empty()){
                    if(st.top() == '{' && s[i] == '}' || st.top() == '[' && s[i] == ']' || st.top() == '(' && s[i] == ')'){
                    }
                    else{
                        count++;
                    }
                    
                    st.pop();
                }
                else{
                    count++;
                }
            }
            
            
            
        }
        if(!st.empty()) count += st.size();
        return count;
    }
};