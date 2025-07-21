class Solution {
public:
    string makeFancyString(string s) {
        if(s.length()<3) return s;
        string str = "";
        int count = 0;
        char check = s[0];
        for(int i = 0 ; i<s.length() ; i++){
            if(check != s[i]){
                check = s[i];
                count = 1;
            }
            else{
                count++;
            }

            if(count<3){
                str += check;
            }
        }
        return str;
    }
};