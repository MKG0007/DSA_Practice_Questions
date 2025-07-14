class Solution {
  public:
  
  bool isPowerFive(string &s, int i, int j) {
        if (s[i] == '0') return false; 
        
        
        long long num = 0;

        for (int k = i; k <= j; k++)
            num = num * 2 + (s[k] - '0');



        if (num == 0) return false;

        while (num > 1) {
            if (num % 5 != 0) return false;
            num /= 5;
        }

        return true;
    }
    int cuts(string s) {
        // code here
        
       
    
        int len = s.length();
        vector<int> dp(len + 1, 1e9);
        dp[0] = 0;

        for (int i = 0; i < len; i++) {
            if (dp[i] == 1e9) continue;
            for (int j = i; j < len; j++) {
                if (isPowerFive(s, i, j)) {
                    dp[j + 1] = min(dp[j + 1], dp[i] + 1);
                }
            }
        }

        return (dp[len] == 1e9) ? -1 : dp[len];
        
        
        
        
    }};