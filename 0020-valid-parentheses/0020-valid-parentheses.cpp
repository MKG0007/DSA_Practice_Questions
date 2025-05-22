class Solution {
public:
    bool checkOpening(char ch){
        if(ch == '{' || ch == '[' || ch == '('){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        int size = s.length();

        stack<char> st;

        for(int i = 0 ; i<size ; i++){
            if(checkOpening(s[i])){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                else{
                    if(st.top() == '{' && s[i] == '}' || st.top() == '[' && s[i] == ']' || st.top() == '(' && s[i] == ')'){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }

        if(!st.empty()){
            return false;
        }

        return true;
        
    }
};