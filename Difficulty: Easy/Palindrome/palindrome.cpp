class Solution {
  public:
    bool isPalindrome(int n) {
        int temp = n;
        int num = 0;
        
        while(temp != 0){
            int digit = temp%10;
            num = num*10 + digit;
            temp = temp/10;
        }
        
        if(num == n) return true;
        
        return false;
    }
};