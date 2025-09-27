class Solution {
public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> isFlipped(n, 0);
        int flipCount = 0, currFlip = 0;

        for (int i = 0; i < n; i++) {
            if (i >= k) {
                currFlip ^= isFlipped[i - k]; // remove expired flip
            }
            if ((arr[i] ^ currFlip) == 0) {  // still 0 after flips
                if (i + k > n) return -1;    // can't flip beyond bounds
                flipCount++;
                currFlip ^= 1;
                isFlipped[i] = 1;
            }
        }
        return flipCount;
    }
};