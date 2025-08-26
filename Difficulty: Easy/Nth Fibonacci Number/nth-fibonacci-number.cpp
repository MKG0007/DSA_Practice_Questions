class Solution {
  public:
    int nthFibonacci(int n) {
        if(n == 0 || n == 1) return n;
        
        int prev = 1;   // stores F(i-1)
        int prev2 = 0;  // stores F(i-2)
        int crr = 0;    // stores current F(i)
        
        for(int i = 2; i <= n; i++){
            crr = prev + prev2;  // Fibonacci relation: F(i) = F(i-1) + F(i-2)
            prev2 = prev;        // shift: update F(i-2) → old F(i-1)
            prev = crr;          // shift: update F(i-1) → current value
        }
        
        return prev;
    }
};
