class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char , int> m;
        for(int i = 0 ; i<magazine.length() ; i++){
            m[magazine[i]]++;
        }

        for(int i = 0 ; i<ransomNote.length() ; i++){
            if(m.find(ransomNote[i]) != m.end()){
                m[ransomNote[i]]--;
                if(m[ransomNote[i]] < 0){
                    return false;
                }
            }
            else{
                return false;
            }
        }

        return true;
    }
};