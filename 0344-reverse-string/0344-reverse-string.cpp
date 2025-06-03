class Solution {
public:
    void reverseString(vector<char>& ss) {

        int s = 0;
        int e = ss.size()-1;

        while(s<e){
            swap(ss[s] , ss[e]);
            s++;
            e--;
        }
        
    }
};