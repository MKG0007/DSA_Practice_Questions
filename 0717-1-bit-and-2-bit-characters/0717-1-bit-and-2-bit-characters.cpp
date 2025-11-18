class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;

        while (i < n - 1) {
            if (bits[i] == 1) {
                i += 2; // two-bit character
            } else {
                i += 1; // one-bit character
            }
        }

        return i == n - 1; // true only if last char is one-bit
    }
};
