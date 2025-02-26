class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 1) return false;
        stack<char> st;
        unordered_map<char , char> m;
        m['('] = ')';
        m['{'] = '}';
        m['['] = ']';

        for(int i = 0 ; i<s.length() ; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    char check = st.top();
                    if(m[check] == s[i]){
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
        if(!st.empty()) return false;
        return true;
    }
};