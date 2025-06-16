class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int size = s.length();
        if(size == 0) return 0;
        unordered_map<int , int> m;
        int left = 0;
        int ans = 1;
        for(int i = 0 ; i<size ; i++){
            if(m.find(s[i]) != m.end()){
                left =max(left ,  m[s[i]]+1);
            }
            m[s[i]] = i;
            ans = max(ans , (i-left+1));

        }

        return ans;

        // string crr = "";
        // string ans = "";
        // for(int i = 0 ; i<s.length() ; i++){
        //     int index = crr.find(s[i]);
        //     if(index>=0){
        //         crr = crr.substr(index+1 , crr.length()-1);
        //         crr += s[i];
        //     }
        //     else{
        //         crr += s[i];
        //     }

        //     if(crr.length()>ans.length()){
        //         ans = crr;
        //     }
        // }
        // return ans.length();
    }
};