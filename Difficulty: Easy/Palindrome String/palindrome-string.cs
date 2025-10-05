class Solution {
    public bool isPalindrome(string s) {
        // code here
        int size = s.Length;
        
        for(int i = 0 ; i<size/2 ; i++){
            if(s[i] != s[size - i -1]){
                return false;
            }
        }
        
        return true;
    }
}
