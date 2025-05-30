class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;

        for(int i = 0 ; i<s.length() ; i++){
            ans ^= s[i];
        }

        for(int i = 0 ; i<t.length() ; i++){
            ans ^= t[i];
        }

        return ans;
    }
};