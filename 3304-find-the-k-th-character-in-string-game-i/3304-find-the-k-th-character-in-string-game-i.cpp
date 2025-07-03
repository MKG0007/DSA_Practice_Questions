class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";

        while(word.length()<k){
            int size = word.length();
            for(int i = 0 ; i<size ; i++){
                char ch = word[i] + 1;
                word +=ch;
            }

        }

        return word[k-1];
        

        
    }
};