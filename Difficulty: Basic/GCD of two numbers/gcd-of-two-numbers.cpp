class Solution {
  public:
    int gcd(int a, int b) {
        
        while(a>0 && b>0){
            if(a<b) b = b%a;
            else a = a%b;
        }
        
        if(a == 0) return b;
        
        return a;
        
        
    }
};
