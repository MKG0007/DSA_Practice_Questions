class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        unordered_map<char , int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        char check = s[0];
        int ans = 0;

        for(int i = 0 ; i<s.length() ; i++){
            if(m[check]<m[s[i]]){
                ans += m[s[i]]-m[check]-m[check];
            }else{
                ans += m[s[i]];
            }
            check = s[i];
        }
        
        return ans;
    }
};