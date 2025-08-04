class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
        int size = s.size();
        
        int i = 0;
        int j = size-1;
        
        while(i<j){
            if(!isalnum(s[i])){
                i++;
            }
            else if(!isalnum(s[j])){
                j--;
            }
            else{
                if(tolower(s[i]) != tolower(s[j])) return false;
                i++;
                j--;
            }
        }
        
        return true;
    }
};