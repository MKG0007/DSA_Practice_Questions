class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for(int i = 3; i <= 3 * n / 4; i++) {
            
            for(int j = i + 1; j < n; j++) {

                int sum = i*i + j*j;
                int k = sqrt(sum);
                if(k <= n) {
                    if(k*k == sum) ans += 2;
                } else break;
            }
        }   
        return ans;
    }
};