class Solution {
public:
bool check(char a){
    char ch = tolower(a);

    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;

    return false;
}

    string sortVowels(string s) {
        vector<char> vowels;

        for(int i = 0 ; i<s.length() ; i++){
            if(check(s[i])){
            vowels.push_back(s[i]);
            }
        }
        sort(vowels.begin() , vowels.end());
        int index = 0;
        for(int i = 0 ; i<s.length() ; i++){
            if(check(s[i])){
            s[i] = vowels[index];
            index++;
            
            }
        }
    return s;
    }
};