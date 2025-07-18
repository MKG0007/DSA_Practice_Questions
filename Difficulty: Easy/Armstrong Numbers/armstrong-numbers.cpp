// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        int temp = n;
        int num = 0;
        
        while(temp != 0){
            int digit = temp%10;
            num += (digit*digit*digit);
            temp = temp/10;
        } 
        
        if(num == n) return true;
        
        return false;
    }
};