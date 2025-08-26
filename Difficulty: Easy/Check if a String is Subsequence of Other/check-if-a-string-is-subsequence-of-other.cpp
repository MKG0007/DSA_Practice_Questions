class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        unordered_map<int , int> m;
        int len1 = s1.length();
        int len2 = s2.length();
        int index = 0;
        
        for(int i = 0 ; i<len2 ; i++){
            if(s1[index] == s2[i]){
                index++;
            }
        }
        
        if(index >= len1) return true;
        return false;
    }
};