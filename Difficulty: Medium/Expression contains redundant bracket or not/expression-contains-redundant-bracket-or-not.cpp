class Solution {
  public:
    bool checkRedundancy(string &s) {
        
        stack<pair<int, int>> st;
        int t = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') {
                if(t && !st.empty()) st.top().second++;
                st.push({i, 0});
                t = 0;
            } else if(s[i] == ')') {
                if(t || st.top().second) {
                    st.pop();
                    t = 0;
                } else {
                    return true;
                }
            } else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                t = 1;                
            }
        }
        
        return false;
    }
};