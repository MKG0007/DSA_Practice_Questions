class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // unordered_set<int> m;
        string crr = "";
        string ans = "";
        for(int i = 0 ; i<s.length() ; i++){
            int index = crr.find(s[i]);
            if(index>=0){
                crr = crr.substr(index+1 , crr.length()-1);
                crr += s[i];
            }
            else{
                crr += s[i];
            }

            if(crr.length()>ans.length()){
                ans = crr;
            }
        }
        return ans.length();
    }
};