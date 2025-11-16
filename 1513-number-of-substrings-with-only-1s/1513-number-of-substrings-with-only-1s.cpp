class Solution {
public:
    int numSub(string s) {
        const long long MOD = 1e9 + 7;
        long long result = 0;
        long long currentOnes = 0;

        for (char ch : s) {
            if (ch == '1') {
                currentOnes++;
                result = (result + currentOnes) % MOD;
            } else {
                currentOnes = 0;
            }
        }

        return result;
    }
};
