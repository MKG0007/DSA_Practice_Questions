class Solution {
public:
    bool check(char ch){
        if(ch == '{' || ch == '(' || ch == '['){
            return true;
        }
        return false;
    }

    bool isValid(string s) {

        unordered_map<char , char> m;
        m['{'] = '}';
        m['['] = ']';
        m['('] = ')';

        stack<char> st;

        for(int i = 0 ; i<s.length() ; i++){
            if(check(s[i])){
                st.push(s[i]);
            }
            else{
                if(st.empty() || m[st.top()] != s[i]){
                    return false;
                }
                st.pop();
            }
        }

        if(!st.empty()){
            return false;
        }
        return true;
    }
};