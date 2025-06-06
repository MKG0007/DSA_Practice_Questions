class Solution {
public:
    bool isSubsequence(string s, string t) {

        int size1 = t.length();
        int size2 = s.length();
        int index1 = 0;
        int index2 = 0;
    
        while(index1<size1 && index2<size2){
            if(s[index2] == t[index1]){
                index2++;
            }
            index1++;
        }

        if(index2 == size2){
            return true;
        }
        return false;
        
    }
};