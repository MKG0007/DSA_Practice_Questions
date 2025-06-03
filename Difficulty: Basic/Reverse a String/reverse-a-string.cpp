// User function Template for C++
class Solution {
  public:
    string reverseString(string& s) {
        int start = 0;
        int end = s.length()-1;
        
        while(start<end){
            swap(s[start] , s[end]);
            start++;
            end--;
        }
        return s;
    }
};
