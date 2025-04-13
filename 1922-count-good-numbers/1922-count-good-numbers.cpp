class Solution {
public:
    const long long mod=1e9+7;
    long long powMod(long long x, long long exp){
        if (exp==0) return 1;
        long long y=(exp&1)?x:1;
        return y*powMod(x*x%mod, exp>>1)%mod;
    }
    int countGoodNumbers(long long n) {
        const long long n0=(n+1)/2 , n1=n-n0;
        return powMod(5, n0)*powMod(4, n1)%mod;
    }
};