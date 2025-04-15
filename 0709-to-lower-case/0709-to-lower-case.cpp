class Solution {
public:
    string toLowerCase(string s) {

        string temp = s;
        string ans = "";
        for(int i = 0 ; i<temp.length() ; i++){
            char ch = tolower(temp[i]);
            ans += ch;
        }

        return ans;
        
    }
};