class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int n : nums) {
            int dcount = 0;
            int dsum = 0;

            for (int j = 1; j * j <= n; j++) {
                if (n % j == 0) {
                    int d1 = j;
                    int d2 = n / j;

                    if (d1 == d2) {
                        dcount++;
                        dsum += d1;
                    } else {
                        dcount += 2;
                        dsum += d1 + d2;
                    }

                    if (dcount > 4) break; 
                }
            }

            if (dcount == 4)
                ans += dsum;
        }

        return ans;
    }
};
