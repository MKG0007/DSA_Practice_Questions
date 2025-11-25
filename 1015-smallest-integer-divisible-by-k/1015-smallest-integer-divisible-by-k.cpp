class Solution {
public:
    int smallestRepunitDivByK(int k) {

        if (k % 2 == 0 || k % 5 == 0) return -1;

        int num = 0;   
        int count = 0;

        for (int i = 0; i < k; i++) {
            num = (num * 10 + 1) % k;  
            count++;

            if (num == 0) {
                return count;
            }
        }

        return -1;
    }
};
