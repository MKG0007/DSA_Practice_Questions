class Solution {
public:
    int lengthOfLastWord(string s) {

        int size = s.length();
        
        int count = 0;
        bool check = true;
        for(int i = 0 ; i<s.length() ; i++){
            if(s[size-i-1] == ' '){

                if(check){
                    continue;
                }
                else{
                    break;
                }
            }
            check = false;

            count++;
        }
        return count;
    }
};