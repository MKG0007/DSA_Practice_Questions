class Solution {
public:
    bool isAnagram(string s, string t) {
        int size1 = s.length();
        int size2 = t.length();
        if(size1 != size2) return false;
        unordered_map<char , int> m;

        for(int i = 0 ; i<size1 ; i++){
            m[s[i]]++;
        }

        for(int i = 0 ; i<size2 ; i++){
            if(m.find(t[i]) != m.end()){
                if(m[t[i]] <= 0){
                    return false;
                }
                m[t[i]]--;
            }
            else{
                return false;
            }
        }

        return true;
    }
};