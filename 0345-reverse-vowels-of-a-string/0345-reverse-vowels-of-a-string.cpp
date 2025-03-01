class Solution {
public:

    bool checkVowel(char ch){
        ch = tolower(ch);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        else{
            return false;
        }
    }

    string reverseVowels(string s) {

        int size = s.length();

        int i = 0;
        int e = size-1;

        while(i<e){

            if(checkVowel(s[i]) && checkVowel(s[e])){
                swap(s[i] , s[e]);
                i++;
                e--;
            }
            else if(checkVowel(s[i])){
                e--;

            }
            else if(checkVowel(s[e])){
                i++;
            }
            else{
                i++;
                e--;
            }
    }
        return s;
    }
};