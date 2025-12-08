class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int size = s.length();
        int count = 0;
        
        for(int i = 0 ; i<size ; i++){
            set<int> check;
            for(int j = i ; j<size ; j++){
                if(check.find(s[j]) != check.end()){
                    break;
                }
                count = max(count , j-i+1);
                check.insert(s[j]);
            }
        }
        
        
        return count;
    }
};
